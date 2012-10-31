#ifndef GENERATED_LOAD_TEST_HPP
#define GENERATED_LOAD_TEST_HPP
namespace glload
{
	class LoadTest
	{
	private:
		//Safe bool idiom. Joy!
		typedef void (LoadTest::*bool_type)() const;
		void big_long_name_that_really_doesnt_matter() const {}
		
	public:
		operator bool_type() const
		{
			return m_isLoaded ? &LoadTest::big_long_name_that_really_doesnt_matter : 0;
		}
		
		int GetNumMissing() const {return m_numMissing;}
		
		LoadTest() : m_isLoaded(false), m_numMissing(0) {}
		LoadTest(bool isLoaded, int numMissing) : m_isLoaded(isLoaded), m_numMissing(isLoaded ? numMissing : 0) {}
	private:
		bool m_isLoaded;
		int m_numMissing;
	};
}
#endif /*GENERATED_LOAD_TEST_HPP*/
