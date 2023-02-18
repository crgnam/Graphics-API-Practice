#include <GL/glew.h>

#include "GAPIP/opengl/vertex_buffer_layout.hpp"
#include "GAPIP/opengl/vertex_array.hpp"
#include "GAPIP/opengl/utils.hpp"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &this->m_RendererID));
	
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &this->m_RendererID))
}

void VertexArray::add_buffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	this->bind();

	vb.bind();
	unsigned int offset = 0;
	const auto& elements = layout.get_elements();
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.get_stride(), (const void*)offset));
		offset += element.count * VertexBufferElement::get_type_size(element.type);
	}

}

void VertexArray::bind() const
{
	GLCall(glBindVertexArray(this->m_RendererID));
}

void VertexArray::unbind() const
{
	GLCall(glBindVertexArray(0));
}