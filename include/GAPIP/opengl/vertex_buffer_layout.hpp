#ifndef __VERTEX_BUFFER_LAYOUT_H_
#define __VERTEX_BUFFER_LAYOUT_H_

#include <vector>

#include <GL/glew.h>

#include "GAPIP/opengl/utils.hpp"

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int get_type_size(unsigned int type) {
		switch (type)
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}

		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout 
{

private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;

public:

	VertexBufferLayout() : m_Stride(0) { };
	~VertexBufferLayout() { };

	template <typename T>
	void push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void push<float>(unsigned int count)
	{
		m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
		m_Stride += count*VertexBufferElement::get_type_size(GL_FLOAT);
	}

	template<>
	void push<unsigned int>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += count*VertexBufferElement::get_type_size(GL_UNSIGNED_INT);
	}

	template<>
	void push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += count*VertexBufferElement::get_type_size(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement> get_elements() const { return this->m_Elements; }
	inline unsigned int get_stride() const { return this->m_Stride; }

};

#endif