
#ifndef MATRIX_STACK_UTIL_H
#define MATRIX_STACK_UTIL_H

#include <stack>
#include <vector>
#include <glm/glm.hpp>

namespace glutil
{
	class MatrixStack
	{
	public:
		MatrixStack()
			: m_currMatrix(1)
		{}

		explicit MatrixStack(const glm::mat4 &initialMatrix)
			: m_currMatrix(initialMatrix)
		{}

		void Push()
		{
			m_stack.push(m_currMatrix);
		}

		void Pop()
		{
			m_currMatrix = m_stack.top();
			m_stack.pop();
		}

		const glm::mat4 &Top() const
		{
			return m_currMatrix;
		}

		void Rotate(const glm::vec3 axis, float angDegCCW);
		void RotateRadians(const glm::vec3 axis, float angRadCCW);
		void RotateX(float angDegCCW);
		void RotateY(float angDegCCW);
		void RotateZ(float angDegCCW);

		void Scale(const glm::vec3 &scaleVec);
		void Scale(float scaleX, float scaleY, float scaleZ) {Scale(glm::vec3(scaleX, scaleY, scaleZ));}
		void Scale(float uniformScale) {Scale(glm::vec3(uniformScale));}

		void Translate(const glm::vec3 &offsetVec);
		void Translate(float transX, float transY, float transZ) {Translate(glm::vec3(transX, transY, transZ));}

		void ApplyMatrix(const glm::mat4 &theMatrix);
		MatrixStack &operator*=(const glm::mat4 &theMatrix) {ApplyMatrix(theMatrix); return *this;}

		void SetMatrix(const glm::mat4 &theMatrix);
		void SetIdentity();

		void Perspective(float degFOV, float aspectRatio, float zNear, float zFar);
		void Orthographic(float left, float right, float bottom, float top, float zNear = -1.0f, float zFar = 1.0f);
		
	private:
		std::stack<glm::mat4, std::vector<glm::mat4> > m_stack;
		glm::mat4 m_currMatrix;
	};

	class PushStack
	{
	public:
		PushStack(MatrixStack &stack)
			: m_stack(stack)
		{
			m_stack.Push();
		}

		~PushStack()
		{
			m_stack.Pop();
		}

		void ResetStack()
		{
			m_stack.Pop();
			m_stack.Push();
		}

	private:
		MatrixStack &m_stack;

		PushStack(const PushStack &);
		PushStack &operator=(const PushStack&);
	};
}



#endif //MATRIX_STACK_UTIL_H
