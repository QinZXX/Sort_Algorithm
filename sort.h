#pragma once
#ifndef SORT_H
#define SORT_H

#include<iostream>
using namespace std;
void Choose(int *a, const size_t& n);//选择排序
void Insert(int *a, const size_t& n);//插入排序
void Bubble(int *a,const size_t &n);//冒泡排序
void objBubble(int *a, const size_t &n);//标准冒泡排序
void betterBubble(int *a, size_t &n);//优化冒泡排序
void Shell(int *a, size_t &n);//希尔排序

int * Merge(int *arr, int left, int right);//归并排序
//1、时间复杂度：O(nlogn)  2、空间复杂度：O(n)  3、稳定排序  4、非原地排序
void merge(int *arr, int left, int mid, int right);

void Merge2(int *a, size_t n);//非递归式归并排序

int* quickSort(int* arr, int left, int right);//快速排序
int partition(int* arr, int left, int right);
//性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(logn)  3、非稳定排序  4、原地排序

void Count(int *a, size_t n);//计数排序
void betterCount(int *a, size_t n);//优化计数排序：统计数组的大小=max-min的差值+1
void stableCount(int *a, size_t n);//稳定计数排序

int qinkuai(int *arr, int left, int right);

#endif // !CHOOSE_H
