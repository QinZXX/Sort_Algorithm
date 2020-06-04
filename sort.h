#pragma once
#ifndef _SORT_H
#define _SORT_H

#include<iostream>
using namespace std;
void SelectionSort(int *a, const size_t& n);//选择排序
void InsertionSort(int *a, const size_t& n);//插入排序
void BubbleSort(int *a,const size_t &n);//冒泡排序
void stdBubbleSort(int *a, const size_t &n);//冒泡排序2
void ShellSort(int *a, size_t &n);//希尔排序

void merge(int*a, int left, int min, int right);
void MergeSort(int *a, size_t n);//(非递归式)归并排序

int partition(int* a, int left, int right);//快速排序 :排好中轴元素位置   返回中轴元素位置
void quickSort(int *a, int left, int right);//递归(if left=right,return)
void qSort(int *a, size_t n);//封装
//性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(logn)  3、非稳定排序  4、原地排序
int partition2(int* a, int left, int right);//方式2：双向扫描

void CountingSort(int *a, size_t n);//计数排序
void betterCountingSort(int *a, size_t n);//优化计数排序：统计数组的大小=max-min的差值+1
void stableCountingSort(int *a, size_t n);//稳定计数排序

#endif 
