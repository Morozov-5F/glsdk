
#include <stdio.h>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glutil/MousePoles.h"
#include "glutil/MatrixStack.h"

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

	void ObjectPole::MouseWheel( int direction, int modifiers, const glm::ivec2 &position )
	{

	}

	void ObjectPole::CharPress( char key )
	{

	}

	ViewPole::ViewPole( const glm::vec3 &target, const ViewDef &viewDef,
		MouseButtons actionButton )
		: m_lookAt(target)
		, m_radCurrXZAngle(0.0)
		, m_radCurrYAngle(-PI_2 / 2.0f)
		, m_radCurrSpin(0.0f)
		, m_viewDef(radiusDef)
		, m_actionButton(actionButton)
		, m_bIsDragging(false)
		, m_rotateScale(PI_2 / 250.0f)
	{}

	glm::mat4 ViewPole::CalcMatrix() const
	{
		//Compute the position vector along the xz plane.
		float cosa = cosf(m_radCurrXZAngle);
		float sina = sinf(m_radCurrXZAngle);

		glm::vec3 currPos(-sina, 0.0f, cosa);

		//Compute the "up" rotation axis.
		//This axis is a 90 degree rotation around the y axis. Just a component-swap and negate.
		glm::vec3 UpRotAxis;

		UpRotAxis.x = currPos.z;
		UpRotAxis.y = currPos.y;
		UpRotAxis.z = -currPos.x;

		//Now, rotate around this axis by the angle.
		glutil::MatrixStack theStack;

		theStack.SetIdentity();
		theStack.RotateRadians(UpRotAxis, m_radCurrYAngle);
		currPos = glm::vec3(theStack.Top() * glm::vec4(currPos, 0.0));

		//Set the position of the camera.
		glm::vec3 tempVec = currPos * m_viewDef.fCurrRadius;
		glm::vec3 cameraPosition = tempVec + m_lookAt;

		//Now, compute the up-vector.
		//The direction of the up-vector is the cross-product of currPos and UpRotAxis.
		//Rotate this vector around the currPos axis given m_currSpin.
		glm::vec3 upVec = glm::cross(currPos, UpRotAxis);

		theStack.SetIdentity();
		theStack.RotateRadians(currPos, m_radCurrSpin);
		upVec = glm::vec3(theStack.Top() * glm::vec4(upVec, 0.0));

//		return CalcLookAtMatrix(cameraPosition, m_lookAt, upVec);
		return glm::lookAt(cameraPosition, m_lookAt, upVec);
	}

	void ViewPole::SetScaleFactor( float rotateScale )
	{
		m_rotateScale = rotateScale;
	}

	void ViewPole::ProcessXChange( int iXDiff, bool bClearY )
	{
		m_radCurrXZAngle = (iXDiff * m_rotateScale) + m_radInitXZAngle;
		if(bClearY)
			m_radCurrYAngle = m_radInitYAngle;
	}

	void ViewPole::ProcessYChange( int iYDiff, bool bClearXZ )
	{
		m_radCurrYAngle = (-iYDiff * m_rotateScale) + m_radInitYAngle;
		if(bClearXZ)
			m_radCurrXZAngle = m_radInitXZAngle;
	}

	void ViewPole::ProcessSpinAxis( int iXDiff, int iYDiff )
	{
		m_radCurrSpin = (iXDiff * m_rotateScale) + m_radInitSpin;
	}

	void ViewPole::BeginDragRotate( const glm::ivec2 &ptStart, RotateMode rotMode )
	{
		m_RotateMode = rotMode;

		m_initialPt = ptStart;

		m_radInitXZAngle = m_radCurrXZAngle;
		m_radInitYAngle = m_radCurrYAngle;
		m_radInitSpin = m_radCurrSpin;

		m_bIsDragging = true;
	}

	void ViewPole::OnDragRotate( const glm::ivec2 &ptCurr )
	{
		glm::ivec2 iDiff = ptCurr - m_initialPt;

		switch(m_RotateMode)
		{
		case RM_DUAL_AXIS_ROTATE:
			ProcessXChange(iDiff.x);
			ProcessYChange(iDiff.y);
			break;
		case RM_BIAXIAL_ROTATE:
			if(abs(iDiff.x) > abs(iDiff.y))
				ProcessXChange(iDiff.x, true);
			else
				ProcessYChange(iDiff.y, true);
			break;
		case RM_XZ_AXIS_ROTATE:
			ProcessXChange(iDiff.x);
			break;
		case RM_Y_AXIS_ROTATE:
			ProcessYChange(iDiff.y);
			break;
		case RM_SPIN_VIEW_AXIS:
			ProcessSpinAxis(iDiff.x, iDiff.y);
		default:
			break;
		}
	}

	void ViewPole::EndDragRotate( const glm::ivec2 &ptEnd, bool bKeepResults )
	{
		if(bKeepResults)
		{
			OnDragRotate(ptEnd);
		}
		else
		{
			m_radCurrXZAngle = m_radInitXZAngle;
			m_radCurrYAngle = m_radInitYAngle;
		}

		m_bIsDragging = false;
	}

	void ViewPole::MoveCloser( bool bLargeStep )
	{
		if(bLargeStep)
			m_viewDef.fCurrRadius -= m_viewDef.largeRadiusDelta;
		else
			m_viewDef.fCurrRadius -= m_viewDef.smallRadiusDelta;

		if(m_viewDef.fCurrRadius < m_viewDef.fMinRadius)
			m_viewDef.fCurrRadius = m_viewDef.fMinRadius;
	}

	void ViewPole::MoveAway( bool bLargeStep )
	{
		if(bLargeStep)
			m_viewDef.fCurrRadius += m_viewDef.largeRadiusDelta;
		else
			m_viewDef.fCurrRadius += m_viewDef.smallRadiusDelta;

		if(m_viewDef.fCurrRadius > m_viewDef.fMaxRadius)
			m_viewDef.fCurrRadius = m_viewDef.fMaxRadius;
	}

	void ViewPole::MouseMove( const glm::ivec2 &position )
	{
		if(m_bIsDragging)
			OnDragRotate(position);
	}

	void ViewPole::MouseClick( MouseButtons button, bool isPressed, int modifiers,
		const glm::ivec2 &position )
	{
		if(isPressed)
		{
			//Ignore all other button presses when dragging.
			if(!m_bIsDragging)
			{
				if(button == m_actionButton)
				{
					if(modifiers & MM_KEY_CTRL)
						this->BeginDragRotate(position, ViewPole::RM_BIAXIAL_ROTATE);
					else if(modifiers & MM_KEY_ALT)
						this->BeginDragRotate(position, ViewPole::RM_SPIN_VIEW_AXIS);
					else
						this->BeginDragRotate(position, ViewPole::RM_DUAL_AXIS_ROTATE);
				}
			}
		}
		else
		{
			//Ignore all other button releases when not dragging
			if(m_bIsDragging)
			{
				if(button == m_actionButton)
				{
					if(m_RotateMode == ViewPole::RM_DUAL_AXIS_ROTATE ||
						m_RotateMode == ViewPole::RM_SPIN_VIEW_AXIS ||
						m_RotateMode == ViewPole::RM_BIAXIAL_ROTATE)
						this->EndDragRotate(position);
				}
			}
		}
	}

	void ViewPole::MouseWheel( int direction, int modifiers,
		const glm::ivec2 &position )
	{
		if(direction > 0)
			this->MoveCloser(!(modifiers & MM_KEY_SHIFT));
		else
			this->MoveAway(!(modifiers & MM_KEY_SHIFT));

	}

	void ViewPole::CharPress( char key )
	{
		switch(key)
		{
		case 'w': OffsetTargetPos(ViewPole::DIR_FORWARD, m_viewDef.largePosOffset); break;
		case 's': OffsetTargetPos(ViewPole::DIR_BACKWARD, m_viewDef.largePosOffset); break;
		case 'd': OffsetTargetPos(ViewPole::DIR_RIGHT, m_viewDef.largePosOffset); break;
		case 'a': OffsetTargetPos(ViewPole::DIR_LEFT, m_viewDef.largePosOffset); break;
		case 'e': OffsetTargetPos(ViewPole::DIR_UP, m_viewDef.largePosOffset); break;
		case 'q': OffsetTargetPos(ViewPole::DIR_DOWN, m_viewDef.largePosOffset); break;

		case 'W': OffsetTargetPos(ViewPole::DIR_FORWARD, m_viewDef.smallPosOffset); break;
		case 'S': OffsetTargetPos(ViewPole::DIR_BACKWARD, m_viewDef.smallPosOffset); break;
		case 'D': OffsetTargetPos(ViewPole::DIR_RIGHT, m_viewDef.smallPosOffset); break;
		case 'A': OffsetTargetPos(ViewPole::DIR_LEFT, m_viewDef.smallPosOffset); break;
		case 'E': OffsetTargetPos(ViewPole::DIR_UP, m_viewDef.smallPosOffset); break;
		case 'Q': OffsetTargetPos(ViewPole::DIR_DOWN, m_viewDef.smallPosOffset); break;
		}
	}

	namespace
	{
		glm::vec3 g_offsets[] =
		{
			glm::vec3( 0.0f,  1.0f,  0.0f),
			glm::vec3( 0.0f, -1.0f,  0.0f),
			glm::vec3( 0.0f,  0.0f, -1.0f),
			glm::vec3( 0.0f,  0.0f,  1.0f),
			glm::vec3( 1.0f,  0.0f,  0.0f),
			glm::vec3(-1.0f,  0.0f,  0.0f),
		};
	}

	void ViewPole::OffsetTargetPos( TargetOffsetDir eDir, float worldDistance )
	{
		glm::vec3 offsetDir = g_offsets[eDir];
		OffsetTargetPos(offsetDir * worldDistance);
	}

	void ViewPole::OffsetTargetPos( const glm::vec3 &cameraOffset )
	{
		glm::mat4 currMat = CalcMatrix();
		glm::fquat orientation = glm::quat_cast(currMat);

		glm::fquat invOrient = glm::conjugate(orientation);
		glm::vec3 worldOffset = invOrient * cameraOffset;

		m_lookAt += worldOffset;
	}
}

