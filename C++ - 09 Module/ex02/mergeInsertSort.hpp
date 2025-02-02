#include "PmergeMe.hpp"

void	putnbr(int nbr)
{
	cout << nbr << " ";
}

template <typename T>
class mergeInsertSort
{
private:
	T		arr;
	double	arrTimeTakes;
public:
	mergeInsertSort(T arr)
	{
		std::clock_t	start = std::clock();
		this->arr = arr;
		fordJohnsonSort(this->arr);
		std::clock_t	end = std::clock();
		arrTimeTakes = double(end - start) / CLOCKS_PER_SEC;
	}
	double	timeTakes(void)
	{
		return arrTimeTakes;
	}
	T	&getarr(void)
	{
		return this->arr;
	}
	void	binaryInsert(T &arr, int value, int start, int end)
	{
		int	mid = (end + start) / 2;
		if (end <= start)
		{
			if (value < arr.at(mid)) {
				arr.insert(arr.begin() + start, value);
			} else {
				arr.insert(arr.begin() + start + 1, value);
			}
			return;
		}
		if (value == arr.at(mid)) {
			arr.insert(arr.begin() + mid, value);
		}
		else if (value > arr.at(mid)) {
			binaryInsert(arr, value, mid + 1, end);
		} else {
			binaryInsert(arr, value, start, mid - 1);
		} 
	}
	void	fordJohnsonSort(T &arr)
	{
		T largerElements;

		if (arr.size() <= 1) return ;

		for (size_t i = 0; i < arr.size() - 1; i += 2) {
			if (arr.at( i ) > arr.at( i + 1 )) {
				swap(arr.at(i), arr.at(i + 1));
			}
		}
		for (size_t i = 1; i < arr.size(); i += 2) {
			largerElements.push_back(arr.at(i));
		}
		fordJohnsonSort(largerElements);
		for (size_t i = 0; i < arr.size(); i += 2) {
			binaryInsert(largerElements, arr.at(i), 0, largerElements.size() - 1);
		}
		arr = largerElements;
	}
};