
#include <stdio.h>
#include "glutil/mouse_poles.h"
#include <glm/gtx/quaternion.hpp>

#ifndef M_PI
#define M_PI 3.14159265f
#endif

const float PI_2 = 1.570796325f;

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))


namespace glutil
{
	ObjectPole::ObjectPole( const glm::vec3 &initialPos,
		const glm::fquat &initialOrient,
		MouseButtons actionButton,
		const ViewProvider *pLookatProvider )
		: m_pView(pLookatProvider)
		, m_orientation(initialOrient)
		, m_objectPos(initialPos)
		, m_actionButton(actionButton)
		, m_RotateMode()
		, m_bIsDragging(false)
		, m_prevPos(initialPos)
		, m_initialPos(initialPos)
		, m_initialOrient(initialOrient)
		, m_rotateScale(PI_2 / 4.0f)
	{}

	void ObjectPole::SetScaleFactor( float rotateScale )
	{
		m_rotateScale = rotateScale;
	}

	glm::mat4 ObjectPole::CalcMatrix() const
	{
		glm::mat4 translateMat(1.0f);
		translateMat[3] = glm::vec4(m_objectPos, 1.0f);

		return translateMat * glm::mat4_cast(m_orientation);
	}

	namespace
	{
		///ObjectPole::NUM_AXES
		glm::vec3 g_axisVectors[] =
		{
			glm::vec3(1.0, 0.0, 0.0),
			glm::vec3(0.0, 1.0, 0.0),
			glm::vec3(0.0, 0.0, 1.0),
		};

		glm::fquat CalcRotationQuat(int eAxis, float degAngle)
		{
			return glm::angleAxis(degAngle, g_axisVectors[eAxis]);
		}
	}


	void ObjectPole::RotateWorldDegrees( const glm::fquat &rot, bool bFromInitial )
	{
		if(!m_bIsDragging)
			bFromInitial = false;

		m_orientation = glm::normalize(rot * (bFromInitial ? m_initialOrient : m_orientation));
	}

	void ObjectPole::RotateLocalDegrees( const glm::fquat &rot, bool bFromInitial )
	{
		if(!m_bIsDragging)
			bFromInitial = false;

		m_orientation = glm::normalize((bFromInitial ? m_initialOrient : m_orientation) * rot);
	}

	void ObjectPole::RotateViewDegrees( const glm::fquat &rot, bool bFromInitial )
	{
		if(!m_bIsDragging)
			bFromInitial = false;

		if(m_pView)
		{
			glm::fquat viewQuat = glm::quat_cast(m_pView->CalcMatrix());
			glm::fquat invViewQuat = glm::conjugate(viewQuat);
			m_orientation = glm::normalize((invViewQuat * rot * viewQuat) *
				(bFromInitial ? m_initialOrient : m_orientation));
		}
		else
			RotateWorldDegrees(rot, bFromInitial);
	}

	void ObjectPole::MouseMove( const glm::ivec2 &position )
	{
		if(m_bIsDragging)
		{
			glm::ivec2 iDiff = position - m_prevPos;

			switch(m_RotateMode)
			{
			case RM_DUAL_AXIS:
				{
					glm::fquat rot = CalcRotationQuat(AXIS_Y, iDiff.x * m_rotateScale);
					rot = glm::normalize(
						CalcRotationQuat(AXIS_X, iDiff.y * m_rotateScale) * rot);
					RotateViewDegrees(rot);
				}
				break;
			case RM_BIAXIAL:
				{
					glm::ivec2 iInitDiff = position - m_initialPos;

					Axis eAxis;
					float degAngle;
					if(abs(iInitDiff.x) > abs(iInitDiff.y))
					{
						eAxis = AXIS_Y;
						degAngle = iInitDiff.x * m_rotateScale;
					}
					else
					{
						eAxis = AXIS_X;
						degAngle = iInitDiff.y * m_rotateScale;
					}

					printf("%f\n", degAngle);

					glm::fquat rot = CalcRotationQuat(eAxis, degAngle);
					RotateViewDegrees(rot, true);
				}
				break;
			case RM_SPIN:
				RotateViewDegrees(CalcRotationQuat(AXIS_Z, -iDiff.x * m_rotateScale));
				break;
			}

			m_prevPos = position;
		}
	}

	void ObjectPole::MouseClick( MouseButtons button, bool isPressed,
		int modifiers, const glm::ivec2 &position )
	{
		if(isPressed)
		{
			//Ignore button presses when dragging.
			if(!m_bIsDragging)
			{
				if(button == m_actionButton)
				{
					if(modifiers & MM_KEY_ALT)
						m_RotateMode = RM_SPIN;
					else if(modifiers & MM_KEY_CTRL)
						m_RotateMode = RM_BIAXIAL;
					else
						m_RotateMode = RM_DUAL_AXIS;

					m_prevPos = position;
					m_initialPos = position;
					m_initialOrient = m_orientation;

					m_bIsDragging = true;
				}
			}
		}
		else
		{
			//Ignore up buttons if not dragging.
			if(m_bIsDragging)
			{
				if(button == m_actionButton)
				{
					MouseMove(position);

					m_bIsDragging = false;
				}
			}
		}
	}

	void ObjectPole::MouseWheel( int direction, const glm::ivec2 &position )
	{

	}
}
