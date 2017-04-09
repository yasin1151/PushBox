#ifndef _HANDLER_TEMPLATE_H_
#define _HANDLER_TEMPLATE_H_

/*
	@brief : �ҵ�Handlerģ����
	@auther: PengYao
	@time  : 2017/1/18
	@ver   : 1.0
*/

#include <vector>

namespace yUtils
{
	template < typename T >
	class HandlerTemplate
	{
	protected:
		std::vector <T*> m_arr;
	public:

		/*
			@brief : ���ڵ��ָ�����������
			@param node : T*
		*/
		void PushBack(T* node);

		/*
			@brief : ��ȡָ���±������
			@param i : �±�
		*/
		T* operator[] (int i);

		/*
			@brief : ��ȡ���鵱ǰԪ�صĸ���
		*/
		size_t GetSize();
	};

	template <typename T>
	void HandlerTemplate<T>::PushBack(T* node)
	{
		m_arr.push_back(node);
	}

	template <typename T>
	T* HandlerTemplate<T>::operator[](int i)
	{
		return m_arr[i];
	}

	template <typename T>
	size_t HandlerTemplate<T>::GetSize()
	{
		return m_arr.size();
	}
}

#endif