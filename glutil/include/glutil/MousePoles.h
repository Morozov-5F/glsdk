
#ifndef MOUSE_POLES_UTIL_H
#define MOUSE_POLES_UTIL_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace glutil
{
	///\addtogroup module_glutil_poles
	///@{
	class ViewProvider
	{
	public:
		virtual ~ViewProvider() {}
		virtual glm::mat4 CalcMatrix() const = 0;
	};

	enum MouseButtons
	{
		MB_LEFT_BTN = 1,
		MB_MIDDLE_BTN,
		MB_RIGHT_BTN,
	};

	enum MouseModifiers
	{
		MM_KEY_SHIFT =	0x01,
		MM_KEY_CTRL =	0x02,
		MM_KEY_ALT =	0x04,
	};

	class ObjectPole
	{
	public:
		ObjectPole(const glm::vec3 &initialPos, const glm::fquat &initialOrient,
			MouseButtons actionButton, const ViewProvider *pLookatProvider);

		glm::mat4 CalcMatrix() const;

		void SetScaleFactor(float rotateScale);
		float GetScaleFactor() const {return m_rotateScale;}

		void RotateWorldDegrees(const glm::fquat &rot, bool bFromInitial = false);
		void RotateLocalDegrees(const glm::fquat &rot, bool bFromInitial = false);
		void RotateViewDegrees(const glm::fquat &rot, bool bFromInitial = false);

		void MouseMove(const glm::ivec2 &position);
		void MouseClick(MouseButtons button, bool isPressed, int modifiers,
			const glm::ivec2 &position);
		void MouseWheel(int direction, int modifiers, const glm::ivec2 &position);

		bool IsDragging() const {return m_bIsDragging;}

	private:
		enum Axis
		{
			AXIS_X,
			AXIS_Y,
			AXIS_Z,

			NUM_AXES,
		};

		enum RotateMode
		{
			RM_DUAL_AXIS,
			RM_BIAXIAL,
			RM_SPIN,
		};

		const ViewProvider *m_pView;
		glm::fquat m_orientation;
		glm::vec3 m_objectPos;

		MouseButtons m_actionButton;

		RotateMode m_RotateMode;
		bool m_bIsDragging;

		glm::ivec2 m_prevPos;
		glm::ivec2 m_initialPos;
		glm::fquat m_initialOrient;
		float m_rotateScale;
	};

	
	struct RadiusDef
	{
		float fCurrRadius;
		float fMinRadius;
		float fMaxRadius;
		float fLargeDelta;
		float fSmallDelta;
	};

	class ViewPole : public ViewProvider
	{
	public:
		ViewPole(const glm::vec3 &target, const RadiusDef &radiusDef,
			MouseButtons eButton = MB_LEFT_BTN);
		virtual ~ViewPole() {}

		glm::mat4 CalcMatrix() const;

		void SetScaleFactor(float rotateScale);
		float GetScaleFactor() const {return m_rotateScale;}

		glm::vec3 GetLookAtPos() const {return m_lookAt;}
		float GetLookAtDistance() const {return m_radius.fCurrRadius;}

		void MouseMove(const glm::ivec2 &position);
		void MouseClick(MouseButtons button, bool isPressed, int modifiers, const glm::ivec2 &position);
		void MouseWheel(int direction, int modifiers, const glm::ivec2 &position);
		void CharPress(char key, float largeIncrement, float smallIncrement);

		bool IsDragging() const {return m_bIsDragging;}

		enum TargetOffsetDir
		{
			DIR_UP,
			DIR_DOWN,
			DIR_FORWARD,
			DIR_BACKWARD,
			DIR_RIGHT,
			DIR_LEFT,
		};

		void OffsetTargetPos(TargetOffsetDir eDir, float worldDistance);
		void OffsetTargetPos(const glm::vec3 &cameraOffset);


	private:
		enum RotateMode
		{
			RM_DUAL_AXIS_ROTATE,
			RM_BIAXIAL_ROTATE,
			RM_XZ_AXIS_ROTATE,
			RM_Y_AXIS_ROTATE,
			RM_SPIN_VIEW_AXIS,
		};

		glm::vec3 m_lookAt;

		float m_radCurrXZAngle;	//Angle around the y-axis. In radians
		float m_radCurrYAngle;		//Angle above the xz plane. In radians
		float m_radCurrSpin;		//Angle spin around the look-at direction. Changes up-vector.
		float m_fRadius;		//Camera distance
		RadiusDef m_radius;

		MouseButtons m_glutActionButton;

		//Used when rotating.
		RotateMode m_RotateMode;
		bool m_bIsDragging;

		glm::ivec2 m_initialPt;

		float m_radInitXZAngle;
		float m_radInitYAngle;
		float m_radInitSpin;

		float m_rotateScale;

		void ProcessXChange(int iXDiff, bool bClearY = false);
		void ProcessYChange(int iYDiff, bool bClearXZ = false);
		void ProcessSpinAxis(int iXDiff, int iYDiff);

		void BeginDragRotate(const glm::ivec2 &ptStart, RotateMode rotMode = RM_DUAL_AXIS_ROTATE);
		void OnDragRotate(const glm::ivec2 &ptCurr);
		void EndDragRotate(const glm::ivec2 &ptEnd, bool bKeepResults = true);

		void MoveCloser(bool bLargeStep = true);
		void MoveAway(bool bLargeStep = true);
	};
	///@}
}



#endif //MOUSE_POLES_UTIL_H
