#ifdef __GNUC__
#pragma once
#endif

#ifndef _BINSEARCH
#define _BINSEARCH 1

#include <vector>

/*
 A template of middle bound binary search.
 T must support operator <, >, ==.
 @return Index of target, if not found return -1
*/
template <typename T>
int binsearch(const std::vector<T> &data, T target) 
{
	if (data.size() == 0) return -1;
	unsigned int l = 0, r = data.size();
	
	while (l <= r)
	{
		// l + (r - l) / 2
		unsigned int mid = (l + r) / 2;
		
		if (data[mid] < target) l = mid + 1;
		else if (data[mid] > target) r = mid - 1;
		else return (int)mid;
	}
	
	return -1;
}

/*
 A template of left bound binary search.
 T must support operator <, >, ==.
 @return Index of target, if not found return -1
*/
template <typename T>
int lbound_binsearch(const std::vector<T> &data, T target)
{
	if (data.size() == 0) return -1;
	unsigned int l = 0, r = data.size();
	
	while (l < r)
	{
		unsigned int mid = (l + r) / 2;
		
		if (data[mid] < target) l = mid + 1;
		else if (data[mid] > target) r = mid;
		else r = mid;
	}
	
	// Replace left to right is OK.
	return (nums[left] == target ? (int)left : -1);
}

/*
 A template of right bound binary search.
 T must support operator <, >, ==.
 @return Index of target, if not found return -1
*/
template <typename T>
int rbound_binsearch(const std::vector<T> &data, T target)
{
	if (data.size() == 0) return -1;
	unsigned int l = 0, r = data.size();
	
	while (l < r)
	{
		unsigned int mid = (l + r) / 2;
		
		if (nums[mid] < target) l = mid + 1;
		else if (nums[mid] > target) r = mid;
		else l = mid + 1;
	}
	
	// Replace left to right is OK.
	return (nums[left - 1] == target ? (int)(left - 1) : -1);
}

#endif
