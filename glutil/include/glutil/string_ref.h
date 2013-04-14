#ifndef STRING_REF_OPENGL_UTILITY_H
#define STRING_REF_OPENGL_UTILITY_H

/**
\file
\brief Contains the string reference utility class.
**/

#include <string>
#include <limits>
#include <stdexcept>
#include <ostream>

namespace refs
{
	/**
	\brief A constant reference to a string.

	This class represents a constant reference to a string, with a given size. The string is
	\em not required to be null-terminated, and it very much can contain null characters.

	The idea is that you use string_ref in interfaces instead of std::string. Why?
	So that the user has the freedom to use string literals, std::string, or any one of the
	dozens of string classes that exist to manage their memory. A function that takes string_ref
	quite simply does not care how the user is managing the memory; it just wants a string.
	
	This serves as a happy medium between giving the user the freedom to use any possible container
	by using a range+template, and forcing the user to use exactly and only one container type.

	This version of basic_string_ref can be implicitly constructed from:
	\li std::string
	\li string literals.

	They can also be constructed from a pointer + a size.

	This class fulfills all of the requirements for a sequential range in C++. It's iterators
	are random-access iterators, and in fact are pointers. It's interface works effectively like
	that of std::basic_string, except that it only provides const access to its members. Oh, and none
	of the convenience functions are here.

	The only mutating operations allowed on this type are clearing and removing elements from the
	front/back of the string.

	\ingroup module_glutil
	**/
	template<typename charT, typename traits = std::char_traits<charT>>
	class basic_string_ref
	{
	public:
		typedef charT value_type;
		typedef const charT * pointer;
		typedef const charT & reference;
		typedef const charT & const_reference;
		typedef const charT * const_iterator;
		typedef const_iterator iterator;
		typedef std::reverse_iterator< const_iterator > const_reverse_iterator;
		typedef const_reverse_iterator reverse_iterator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		static const size_type npos = size_type(-1);

		// construct/copy
		basic_string_ref() : m_data(NULL), m_size(0) {}

		basic_string_ref(const charT * str) : m_data(str), m_size(traits::length(str)) {}
		template<typename Allocator>
		basic_string_ref(const std::basic_string< charT, traits, Allocator > & str)
			: m_data(&str[0]), m_size(str.size()) {}
		basic_string_ref(const charT * str, size_type len) : m_data(str), m_size(len) {}

		const_iterator begin() const {return m_data;}
		const_iterator end() const {return m_data + m_size;}
		const_iterator cbegin() const {return m_data;}
		const_iterator cend() const {return m_data + m_size;}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
		const_reverse_iterator rend() const {return const_reverse_iterator(begin());}
		const_reverse_iterator crbegin() const  {return const_reverse_iterator(cend());}
		const_reverse_iterator crend() const {return const_reverse_iterator(cbegin());}

		size_type size() const {return m_size;}
		size_type length() const {return m_size;}
		size_type max_size() const {return std::numeric_limits<size_type>::max();}
		bool empty() const {return m_size == 0;}

		const charT & operator[](size_t i) const {return m_data[i];}
		const charT & at(size_t i) const
		{
			if(i >= m_size)
				throw std::out_of_range();
			return m_data[i];
		}

		const charT & front() const {return m_data[0];}
		const charT & back() const {return m_data[m_size - 1];}
		const charT * data() const {return m_data;}

		std::basic_string< charT, traits > str() const {return std::basic_string< charT, traits >(m_data, m_size); }

		void clear() {m_size = 0; m_data = NULL;}
		void remove_prefix(size_type n)
		{
			m_data += n;
			m_size -= n;
			if(m_size <= 0)
				clear();
		}

		void remove_suffix(size_type n)
		{
			m_size -= n;
			if(m_size <= 0)
				clear();
		}

		void pop_front() {remove_prefix(1);}
		void pop_back() {remove_suffix(1);}

	private:
		const charT *m_data;
		size_t m_size;
	};

	typedef basic_string_ref<char> string_ref;

	template<typename charT, typename traits>
	std::basic_ostream<charT, traits> operator<<(std::basic_ostream<charT, traits> &ostream, basic_string_ref<charT, traits> data)
	{
		if(!data.empty())
			ostream.write(data.data(), data.size());

		return ostream;
	}
}

#endif //STRING_REF_OPENGL_UTILITY_H
