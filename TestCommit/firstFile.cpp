#include <vector>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	int targetNum = 0 ;
	for(int i=0; i<array.size();i++){
	 	targetNum = targetSum - array[i] ;
		for(int j = i+1; j<array.size() ;j++){
			if(targetNum == array[j])
				return vector<int>{array[i],array[j]} ;
		}
	}
return {}  ;

}
