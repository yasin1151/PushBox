#ifndef _MEM_POOL_H_
#define _MEM_POOL_H_

/*
	@brief : һ���򵥵��ڴ��
	@auther: PengYao
	@time  : 2017/1/17
	@ver   : 1.0
*/

#include <list>
namespace yUtils
{
	template <typename T>
	class CMemPool
	{
	public:
		/*
		*	@param beginSize : ��ʼnew���ڴ�ĸ���
		*/
		CMemPool(int beginSize = 10, int chunkSize = sizeof(T))
			:m_chunkSize(chunkSize)
		{
			//addMem(beginSize);
		}

		virtual ~CMemPool()
		{
			clear();
		}

		/*
		*@brief : ȥ����һ���ڴ���ⲿ
		*/
		T* Alloc();

		/**@brief : �����ⲿ�ڴ�
		@param ptr : ��Ҫ�����յ��ڴ�
		*/
		void  Delete(T* ptr);

		
	protected:

		/*
			@brief : �ڷ����ڴ�ʱ����
		*/

		virtual void onAllocMem(T* ptr)
		{
			
		}


		/*
			@brief : �������ڴ�����
		*/
		virtual void OnAddMem(std::list<T*>& listHasMem)
		{

		}

		/*
			@brief : �ڻ����ڴ�ʱ����
		*/
		virtual void OnDelete(T* ptr)
		{
			
		}

		/*
			@brief : �������ڴ�ʱ����
		*/
		virtual void OnClearup(T* ptr)
		{
			
		}

		/*
		@brief : ���ӷ�����ڴ���Ŀ
		*/
		void addMem(int size = 0);

		/*
		@brief : �������е��ڴ�
		*/
		void clear();


		void Init();

		std::list<T*> m_curUseMem;				//��ǰ�Ѿ�ʹ�õ��ڴ��,����Ҫ�ͷŵ��ڴ�
		std::list<T*> m_curHasMem;				//��ǰ����ʹ�õ��ڴ��
		size_t		  m_chunkSize;				//�ڴ��Ĵ�С
	};

	template <typename T>
	void CMemPool<T>::addMem(int size)
	{
		size_t curSize = m_curUseMem.size();
		if (curSize <= 0 && size != 0)
		{
			curSize = size;
		}

		for (int i = 0; i < curSize * 3 / 2; i++)
		{
			//ֻ�ֿռ䣬�����ù��캯��
			//m_curHasMem.push_back(static_cast<T*>(operator new (sizeof(T))));
			OnAddMem(m_curHasMem);
		}
	}

	template <typename T>
	T* CMemPool<T>::Alloc()
	{
		if (m_curHasMem.empty())
		{
			addMem();
		}

		//�ӿ���ʹ�õ��ڴ����ȡ���������뵽�Ѿ�ʹ�õ��ڴ����
		T* retBuf = m_curHasMem.back();
		m_curHasMem.pop_back();
		m_curUseMem.push_back(retBuf);

		onAllocMem(retBuf);

		return retBuf;
	}

	template <typename T>
	void  CMemPool<T>::Delete(T* ptr)
	{
		if (!ptr)
		{
			return;
		}

		m_curUseMem.remove(ptr);
		m_curHasMem.push_back(ptr);
		
		OnDelete(m_curHasMem.back());
	}

	template <typename T>
	void CMemPool<T>::clear()
	{
		if (!m_curUseMem.empty())
		{
			for (auto i : m_curUseMem)
			{
				OnClearup(i);
				delete i;
			}
		}

		if (!m_curHasMem.empty())
		{
			for (auto i : m_curHasMem)
			{
				OnClearup(i);
				delete i;
			}
		}
	}

	template <typename T>
	void CMemPool<T>::Init()
	{
		addMem(10);
	}
}


#endif// _MEM_POOL_H_