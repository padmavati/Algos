package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class MaxSumSubArray {

    private ArrayList<Integer> maxset(ArrayList<Integer> a) {
        ArrayList<Integer> maxSubArray = new ArrayList<>();
        int lowerIndex = 0, upperIndex = 0, currentLowerIndex = -1, currentUpperIndex = -1;
        boolean firstTime = true;
        long maxSum = 0, currentSum = 0;
        for (int index = 0; index < a.size(); index++) {
            if (a.get(index) >= 0) {
                currentSum += a.get(index);
                if (currentLowerIndex == -1)
                    currentLowerIndex = index;
                currentUpperIndex = index;
            } else if ((currentSum > maxSum) || (currentSum == maxSum && upperIndex - lowerIndex < currentUpperIndex - currentLowerIndex) || (firstTime && currentLowerIndex >= 0 && currentUpperIndex >= 0)) {
                lowerIndex = currentLowerIndex;
                upperIndex = currentUpperIndex;
                currentLowerIndex = currentUpperIndex = -1;
                maxSum = currentSum;
                currentSum = 0;
                firstTime = false;
            } else {
                currentLowerIndex = currentUpperIndex = -1;
                currentSum = 0;
            }
        }
        if (currentSum > maxSum || (currentSum == maxSum && upperIndex - lowerIndex < currentUpperIndex - currentLowerIndex)) {
            lowerIndex = currentLowerIndex;
            upperIndex = currentUpperIndex;
        }
        for (int index = lowerIndex; index >= 0 && index <= upperIndex && a.get(index) >= 0; index++) {
            maxSubArray.add(a.get(index));

        }
        return maxSubArray;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int size = scanner.nextInt();
        ArrayList<Integer> input = new ArrayList<>();

        for (int index = 0; index < size; index++)
            input.add(scanner.nextInt());

        MaxSumSubArray maxSumSubArray = new MaxSumSubArray();
        ArrayList<Integer> list = maxSumSubArray.maxset(input);
        for (Integer number : list) {
            System.out.printf("%d\t", number);
        }
    }
}
