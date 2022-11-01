#include <iostream>
#include <random>

void shuffle(std::vector<int>& arr){
    std::random_device random;
    std::mt19937 randomer(random());
    std::shuffle(arr.begin(), arr.end(), randomer);
}

bool isSorted(const std::vector<int>& arr){
    for(int i=0; i<arr.size()-1; i++)
        if(arr[i]>arr[i+1])
            return false;
    return true;
}

void bogosort(std::vector<int> arr) {  // Sorts array a[0..n-1] using Bogo Sort
    // if array is not sorted then shuffle the array again
    while (!isSorted(arr))
        shuffle(arr);
}

int main(){
	std::vector<int> arr = {3, 2, 5, 1, 0, 4};
	bogosort(arr);
	for(int i=0; i<arr.size(); i++)
		std::cout << arr[i] << " ";
	return 0;
}