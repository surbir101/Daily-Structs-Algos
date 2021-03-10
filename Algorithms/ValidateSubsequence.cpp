/*
Validate Subsequence

Question:
Given two non empty arrays of integers write a function
that determines whether the second array is a subsequence
of the first one.

*Hint: Subsequence doesnt neccessarily have to mean the elements are
right next to eachother, or adjacent, only that they appear in the same
order.

Answer:

Step through the first array and search for the first value in the subsequence,
when found increment index of subsequence and search for second element, until
you reach the end of the first array or the end of the subsequence.



*/

// Solution 1: O(n) time | O(1) space

bool isValidSubsequence(vector<int> array, vector<int> sequence) {

	int seqIndex = 0; // index of element we are currently searching for in main array
	for(auto value : array){ //step through main array
		if(seqIndex == sequence.size())
			break; // all elements found can exit loop
		if(sequence[seqIndex] == value)
			seqIndex++ ; //move to next value in sequence
	}
	return seqIndex == sequence.size();  // Returns true iff all elements in sequence array are found

}
