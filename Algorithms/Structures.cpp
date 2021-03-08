/*

   Question:
   Two Number Sum, if any two numbers in an array of distinct values
   add up to the target sum, return the two numbers in any order in a
   new array. Otherwise return an empty array.

   Answer:
   Can be done in three ways:
   1.iterativly
   2.with an additional data structure (map)
   3.by sorting first and beginning from opposite ends
   of the array and working inward.

 */

 // Solution 1 : O(n^2) time | O(1) space

vector<int> twoNumberSum(vector<int> array, int targetSum) {

 	int targetNum = 0 ;  //num we are searching for
 	int size = array.size() ; //holds number of elements in array

 	for(int i=0; i<size-1; i++)
 	{
 		targetNum = targetSum - array[i] ; // targetNum holds number that would complete two sum
 		for(int j=i+1; j<size; j++)
 		{
 			if(array[j] == targetNum)
 				return vector<int>{array[i],array[j]} ;
 		}
 	}

 	return {} ; //if loop exits then two sum was not found return empty vector

}

// Solution 2 : O(n) time | O(n) space

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	unordered_set<int> set ; //allows for constant time lookup
	int targetNum = 0 ; //holds value we are looking for
	for(int num : array) //traverse array
	{
		targetNum = targetSum - num ; //targetNum holds value we are looking for
		if(set.find(targetNum) == set.end())
			set.insert(num) ; //if value is not found in set add it
		else
			return vector<int>{num,targetNum} ; //if found we are done return values
	}

	return {} ; //if for loop finishes without returning two sum value not found

}

//Solution 3 : O(nlog(n)) time | 0(1) space 


vector<int> twoNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(), array.end()) ;

	int left = 0 ; //holds beginning index of array
	int right = array.size() - 1 ; //holds ending index of array
	int targetNum = 0 ; // holds value of two numbers summed checked agains targetSum

	while(left < right)
	{
		targetNum = array[left] + array[right] ;
		if(targetNum  == targetSum)
			return vector<int>{array[left],array[right]} ;
		else if (targetNum < targetSum )
			left++ ;
		else
			right-- ;
	}
	return {} ; //if for loop ends targetSum values not present in array
}
