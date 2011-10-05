
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
		void MouseWheel(int direction, const glm::ivec2 &position);

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

	///@}
}



#endif //MOUSE_POLES_UTIL_H
