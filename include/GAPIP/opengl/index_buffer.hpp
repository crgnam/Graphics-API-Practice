#ifndef __INDEX_BUFFER_H_
#define __INDEX_BUFFER_H_

class IndexBuffer {
	private:
		unsigned int m_RendererID;
		unsigned int m_Count;

	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		// Things we might need to modify data:
		// void lock();
		// void set_data(const void* data);
		// void unlock();

		void bind() const;
		void unbind() const;

		inline unsigned int get_count() const { return this->m_Count; }
};

#endif