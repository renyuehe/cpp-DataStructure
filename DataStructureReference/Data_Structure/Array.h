#ifndef __ARRAY_H__
#define __ARRAY_H__

using namespace std;

const int initialLen = 10;
template <class T>
class Array{
public:
	Array(int len = initialLen){
		T *p = new T[len];
		m_data = p;
		m_capacity = len;
		m_size = 0;
	}
	int capacity(){
		return m_capacity;
	}
	int size(){
		return m_size;
	}
	void resize(int len){
		T *p = new T[len];
		for (int i = 0; i < m_size; ++i){
			p[i] = m_data[i];
		}
		delete[] m_data;
		m_data = p;
		m_capacity = len;
	}
	bool isEmpty(){
		return m_size == 0;
	}
	void print(){
		cout << "Array: ";
		cout << "Capacity = " << m_capacity << ", " << "Size = " << m_size << endl;
		cout << '[';
		for (int i = 0; i < m_size; ++i){
			cout << m_data[i];
			if (i != m_size - 1){
				cout << ',';
			}
		}
		cout << ']' << endl;
	}
	//���Ӳ���
	void add(int index, T num);
	void addFirst(T num);
	void addLast(T num);
	//ɾ������
	T remove(int index);
	T removeFirst();
	T removeLast();
	void removeElement(T num);
	//�޸Ĳ���
	void set(int index, T num);
	//���Ҳ���
	T get(int index);
	int find(T num);
	bool contains(T num);
private:
	T *m_data;       //��������
	int m_capacity;  //��������
	int m_size;      //�����С
};

template <typename T>
void Array<T>::add(int index, T num){
	if (index < 0 || index > m_size){
		cout << "���λ�÷Ƿ���" << endl;
		return;
		//throw 0;  //�������ʹ�����쳣������Ҳ����
	}
	if (m_size >= m_capacity){
		resize(2 * m_capacity);
	}
	for (int i = m_size; i > index; --i){
		m_data[i] = m_data[i - 1];
	}
	m_data[index] = num;
	m_size++;
}
template <class T>
void Array<T>::addFirst(T num){
	add(0, num);
}
template <class T>
void Array<T>::addLast(T num){
	if (m_size >= m_capacity){
		resize(2 * m_capacity);
	}
	m_data[m_size] = num;
	m_size++;
}

template <class T>
T Array<T>::remove(int index){
	if (index < 0 || index >= m_size){
		cout << "ɾ��λ�÷Ƿ���" << endl;
		return NULL;
	}
	T res = m_data[index];
	m_size--;
	for (int i = index; i < m_size; ++i){
		m_data[i] = m_data[i + 1];
	}
	if (m_size < m_capacity / 4){
		resize(m_capacity / 2);
	}
	return res;
}
template <class T>
T Array<T>::removeFirst(){
	T res = m_data[0];
	remove(0);
	return res;
}
template <class T>
T Array<T>::removeLast(){
	if (m_size == 0){
		cout << "ɾ��λ�÷Ƿ���" << endl;
		return NULL;
	}
	m_size--;
	if (m_size < m_capacity / 4){
		resize(m_capacity / 2);
	}
	return m_data[m_size];
}
template <class T>
void Array<T>::removeElement(T num){
	int flag = find(num);
	if (flag != -1){
		remove(flag);
	}
}

template <class T>
void Array<T>::set(int index, T num){
	if (index < 0 || index >= m_size){
		cout << "�޸�λ�÷Ƿ���" << endl;
		return;
	}
	m_data[index] = num;
}

template <class T>
T Array<T>::get(int index){
	if (index < 0 || index >= m_size){
		cout << "����λ�÷Ƿ���" << endl;
		return NULL;
	}
	return m_data[index];
}
template <class T>
int Array<T>::find(T num){
	for (int i = 0; i < m_size; ++i){
		if (m_data[i] == num){
			return i;
		}
	}
	return -1;
}
template <class T>
bool Array<T>::contains(T num){
	for (int i = 0; i < m_size; ++i){
		if (m_data[i] == num){
			return true;
		}
	}
	return false;
}

#endif