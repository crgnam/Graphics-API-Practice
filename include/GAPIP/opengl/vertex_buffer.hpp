#ifndef __VERTEX_BUFFER_H_
#define __VERTEX_BUFFER_H_

class VertexBuffer {
	private:
		unsigned int m_RendererID;

	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		// Things we might need to modify data:
		// void lock();
		// void set_data(const void* data);
		// void unlock();

		void bind() const;
		void unbind() const;
};

#endif