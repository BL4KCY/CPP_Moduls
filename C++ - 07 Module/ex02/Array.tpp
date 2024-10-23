#ifndef ARRAY_TPP
# define ARRAY_TPP
# include <stdexcept>
# include <inttypes.h>
# include <string>
# include <iostream>

using std::cout;
using std::string;
using std::endl;


template <class T>
class Array
{
	T*			array;
	uint32_t	_size;
public:
	Array(){this->_size = 0; array = NULL;}
	~Array() {if (this->_size) delete[] array;}
	Array(unsigned int n)
	{
		this->array = new T[n];
		this->_size = n;
	}
	Array(Array const &rhs)
	{
		if (rhs._size)
		{
			this->array = new T[rhs._size];
			this->_size = rhs._size;
			for (uint32_t i = 0; i < this->_size; i++)
				(*this)[i] = rhs.array[i];
		}
		else
		{
			if (this->_size)
				delete[] this->array;
			this->array = NULL;
			this->_size = 0;
		}
	}
	Array&	operator = (const Array	&rhs)
	{
		if (this->array != rhs.array)
		{
			if (rhs._size)
			{
				if (this->_size)
				{
					delete[] this->array;
					this->_size = 0;
				}
				this->array = new T[rhs._size];
				this->_size = rhs._size;
				for (uint32_t i = 0; i < this->_size; i++)
					(*this)[i] = rhs.array[i];
			}
			else
			{
				this->array = NULL;
				this->_size = 0;
			}
		}
		else
			cout << "catched!!" << endl;
		return (*this);
	}
	T&		operator [] (uint32_t index)
	{
		if (index >= this->_size)
			throw std::out_of_range("index out of range");
		return(this->array[index]);
	}
	uint32_t	size(void) const
	{
		return (this->_size);
	}
};


#endif // ARRAY_TPP