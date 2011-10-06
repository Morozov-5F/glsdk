
#ifndef MOUSE_POLES_UTIL_H
#define MOUSE_POLES_UTIL_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace glutil
{
	///\addtogroup module_glutil_poles
	///@{

	///Abstract base class used by ViewPole to identify that it provides a viewing matrix.
	class ViewProvider
	{
	public:
		virtual ~ViewProvider() {}

		///Computes the camera matrix.
		virtual glm::mat4 CalcMatrix() const = 0;
	};

	///The possible buttons that Poles can use.
	enum MouseButtons
	{
		MB_LEFT_BTN = 1,	///<The left mouse button.
		MB_MIDDLE_BTN,		///<The middle mouse button.
		MB_RIGHT_BTN,		///<The right mouse button.
	};

	///Bitfield for modifiers that may be held down while mouse movements go on.
	enum MouseModifiers
	{
		MM_KEY_SHIFT =	0x01,	///<One of the shift keys.
		MM_KEY_CTRL =	0x02,	///<One of the control keys.
		MM_KEY_ALT =	0x04,	///<One of the alt keys.
	};

	/**
	\brief Mouse-based control over the orientation and position of an object.

	This Pole speaks of three spaces: local, world, and view. Local refers to the coordinate system
	of vertices given to the matrix that this Pole generates. World represents the \em output coordinate
	system. So vertices enter in local and are transformed to world. View represents the space
	provided by the ViewProvider given to the constructor.

	This Pole is given an action button, which it will listen for click events from. When
	the action button is held down and the mouse moved, the object's orientation will change,
	relative to the orientation of the view. But only if a ViewProvider (such as ViewPole) was
	provided; otherwise, the rotation will be relative to the world.
	
	If no modifier keys (shift, ctrl, alt) were held when the click was given, then the object will be
	oriented in both the view-space X and Y axes. If the CTRL key is held when the click was given, then
	the object will only rotate around either the X or Y axis. The selection is based on whether
	the X or the Y mouse coordinate is farthest from the initial position when dragging started.
	If the ALT key is held, then the object will rotate about the Z axis, and only the X position
	of the mouse affects the object.

	More information on \ref module_glutil_poles "mouse poles is available."
	**/
	class ObjectPole
	{
	public:
		/**
		\brief Creates an object pole with a given initial position and orientation.
		
		\param initialPos The starting position of the pole.
		\param initialOrient The initial orientation of the pole.
		\param actionButton The mouse button to listen for. All other mouse buttons are ignored.
		\param pLookatProvider An object that will compute a view matrix. This defines the view space
		that orientations can be relative to. If it is NULL, then orientations will be relative to the world.
		**/
		ObjectPole(const glm::vec3 &initialPos, const glm::fquat &initialOrient,
			MouseButtons actionButton, const ViewProvider *pLookatProvider);

		///Generates the local-to-world matrix for this object.
		glm::mat4 CalcMatrix() const;

		///Sets the scaling factor for orientation changes.
		void SetScaleFactor(float rotateScale);
		///Gets the current scaling factor for orientation changes.
		float GetScaleFactor() const {return m_rotateScale;}

		/**
		\name Input Providers

		These functions provide input, since Poles cannot get input for themselves. See
		\ref module_glutil_poles "the Pole manual" for details.
		**/
		///@{

		/**
		\brief Notifies the ObjectPole of a mouse button being pressed or released.
		
		\param button The button being pressed or released.
		\param isPressed Set to true if \a button is being pressed.
		\param modifiers A bitfield of MouseModifiers that specifies the modifiers being held down currently.
		\param position The mouse position at the moment of the mouse click.
		**/
		void MouseClick(MouseButtons button, bool isPressed, int modifiers,
			const glm::ivec2 &position);

		///Notifies the ObjectPole that the mouse has moved to the given absolute position.
		void MouseMove(const glm::ivec2 &position);

		/**
		\brief Notifies the ObjectPole that the mouse wheel has been rolled up or down.
		
		\param direction A positive number if the mouse wheel has moved up, otherwise it should be negative.
		\param modifiers The modifiers currently being held down when the wheel was rolled.
		\param position The absolute mouse position at the moment the wheel was rolled.
		**/
		void MouseWheel(int direction, int modifiers, const glm::ivec2 &position);

		/**
		\brief Notifies the ObjectPole that a character has been entered.

		Not yet used in the ObjectPole.

		\param key ASCII keycode.
		**/
		void CharPress(char key);
		///@}

		///Returns true if the mouse is currently being dragged.
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

		void RotateWorldDegrees(const glm::fquat &rot, bool bFromInitial = false);
		void RotateLocalDegrees(const glm::fquat &rot, bool bFromInitial = false);
		void RotateViewDegrees(const glm::fquat &rot, bool bFromInitial = false);

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

	///Utility object containing information about how the ViewPole can move around.
	struct ViewDef
	{
		float fCurrRadius;		///<The initial radius of the view from the target point.
		float fMinRadius;		///<The closest the radius to the target point can get.
		float fMaxRadius;		///<The farthest the radius to the target point can get.
		float largeRadiusDelta;	///<The radius change to use when the SHIFT key isn't held while mouse wheel scrolling.
		float smallRadiusDelta;	///<The radius change to use when the SHIFT key \em is held while mouse wheel scrolling.
		float largePosOffset;	///<The position offset to use when the SHIFT key isn't held while pressing a movement key.
		float smallPosOffset;	///<The position offset to use when the SHIFT key \em is held while pressing a movement key.
	};

	/**
	\brief Mouse-based control over the orientation and position of the camera. 
	
	This view controller is based on a target point, which is centered in the camera, and an
	orientation around that target point that represents the camera. The Pole allows the user
	to rotate around this point, move closer to/farther from it, and to move the point itself.

	This Pole is given a ViewDef that defines a number of size parameters and limitations.

	This Pole is given an action button, which it will listen for click events from. If the
	mouse button is clicked and no modifiers are pressed, the the view will rotate
	around the object in both the view-local X and Y axes. If the CTRL key is held, then it
	will rotate about the X or Y axes, based on how far the mouse is from the starting point in the
	X or Y directions. If the ALT key is held, then the camera will spin in the view-local Z direction.

	Scrolling the mouse wheel up or down moves the camera closer or farther from the object, respectively.
	The distance is taken from ViewDef::largeRadiusDelta. If the SHIFT key is held while scrolling, then the
	movement will be the ViewDef::smallRadiusDelta value instead.

	The target point can be moved, relative to the current view, with the WASD keys. W/S move forward and
	backwards, while A/D move left and right, respectively. Q and E move down and up, respectively. The
	offset applied to the position is ViewDef::largePosOffset; if SHIFT is held, then ViewDef::smallPosOffset
	is used instead.
	**/
	class ViewPole : public ViewProvider
	{
	public:
		/**
		\brief Creates a view pole with the given initial target position, view definition, and action button.
		
		\param target The initial position of the target point around which the camera revolves.
		\param viewDef The viewport definition to use.
		\param actionButton The mouse button to listen for. All other mouse buttons are ignored.
		**/
		ViewPole(const glm::vec3 &target, const ViewDef &viewDef,
			MouseButtons actionButton = MB_LEFT_BTN);
		virtual ~ViewPole() {}

		///Generates the world-to-camera matrix for the view.
		glm::mat4 CalcMatrix() const;

		///Sets the scaling factor for orientation changes.
		void SetScaleFactor(float rotateScale);
		///Gets the current scaling factor for orientation changes.
		float GetScaleFactor() const {return m_rotateScale;}

		///Retrieves the current world-space target point.
		glm::vec3 GetLookAtPos() const {return m_lookAt;}

		///Retrieves the world-space distance the camera currently is from the target point.
		float GetLookAtDistance() const {return m_viewDef.fCurrRadius;}

		/**
		\name Input Providers

		These functions provide input, since Poles cannot get input for themselves. See
		\ref module_glutil_poles "the Pole manual" for details.
		**/
		///@{
		void MouseClick(MouseButtons button, bool isPressed, int modifiers, const glm::ivec2 &position);
		void MouseMove(const glm::ivec2 &position);
		void MouseWheel(int direction, int modifiers, const glm::ivec2 &position);
		void CharPress(char key);
		///@}

		///Returns true if the mouse is being dragged.
		bool IsDragging() const {return m_bIsDragging;}

	private:
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

		enum RotateMode
		{
			RM_DUAL_AXIS_ROTATE,
			RM_BIAXIAL_ROTATE,
			RM_XZ_AXIS_ROTATE,
			RM_Y_AXIS_ROTATE,
			RM_SPIN_VIEW_AXIS,
		};

		glm::vec3 m_lookAt;

		float m_radCurrXZAngle;		//Angle around the y-axis. In radians
		float m_radCurrYAngle;		//Angle above the xz plane. In radians
		float m_radCurrSpin;		//Angle spin around the look-at direction. Changes up-vector.
		ViewDef m_viewDef;

		MouseButtons m_actionButton;

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
