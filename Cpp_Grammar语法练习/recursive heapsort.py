# -*- coding: utf-8 -*-
"""
Created on Mon Nov 13 15:05:32 2023

@author: Hegel
"""

# Solution 2, Recursion, Time O(nlogn), Space (logn)
def heapSort(arr):
    n = len(arr)      
    for i in range(n//2, -1, -1):  # Build heap
        heapify(arr, n, i) 
    for i in range(n-1, 0, -1):  # sort
        arr[i], arr[0] = arr[0], arr[i] # Swap
        heapify(arr, i, 0) # Heapify 
# Heapify, recursion, Time O(logn), Space O(logn)         
def heapify(arr, size, i):    
    larger = i 
    left = 2 * i + 1
    right = 2 * i + 2
    if left < size and arr[i] < arr[left]:
        larger = left
    if right < size and arr[larger] < arr[right]:
        larger = right
    if larger != i:
        arr[i], arr[larger] = arr[larger], arr[i] #swap
        heapify(arr, size, larger) #heapify again
arr = [19, 33, 4, 61, 5, 38, -36, 21, 0]
heapSort(arr)
print("Heap sort (recursion): " + str(arr))