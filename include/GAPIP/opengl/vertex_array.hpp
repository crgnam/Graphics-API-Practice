#ifndef __VERTEX_ARRAY_H_
#define __VERTEX_ARRAY_H_

#include "GAPIP/opengl/vertex_buffer.hpp"
#include "GAPIP/opengl/vertex_buffer_layout.hpp"

class VertexArray 
{
private:
	unsigned int m_RendererID;

public:
	VertexArray();
	~VertexArray();

	void add_buffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void bind() const;
	void unbind() const;
};

#endif