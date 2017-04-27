/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ArrayDemo;

import java.util.Scanner;

/**
 *
 * @author shengzhang0830
 */
public class ArrayDemo {
    
    // getAverage computes the averages of an array of ints and returns the result as a float
    static float getAverage(int[] data)
    {
        int total = 0;
        float average = 0;
        for (int element: data)
        {
            total = total + element;
        }
        if (data.length > 0)
        {
            average = (float) total / data.length;
        }
        return average;
    }

    // getLargest returns the largest number of an array of ints
    static int getLargest(int[] data)
    {
        int largest = data[0];
        for (int i = 0; i < data.length; i++)
        {
            if (data[i] > largest)
            {
                largest = data[i];
            }
        }
        return largest;
    }

    // getSmallest returns the smallest number of an array of ints
    static int getSmallest(int[] data)
    {
        int smallest = data[0];
        for (int i = 0; i < data.length; i++)
        {
            if (data[i] < smallest)
            {
                smallest = data[i];
            }
        }
        return smallest;
    } 

    
    public static void main(String[] args)
    {
        final int LENGTH = 5;
        int[] data = new int[LENGTH];
        
        // Use Scanner to read in data
        Scanner in = new Scanner(System.in);
        
        for(int i = 0; i < data.length; i++)
        {
            System.out.println("Enter value for index " + i + ": ");
            data[i] = in.nextInt();
        }
        
        // Compute the results using defined functions
        float average = getAverage(data);
        int largest = getLargest(data);
        int smallest = getSmallest(data);
        
        // Print out the results
        System.out.println("The average of these five numbers is " + average + ".");
        System.out.println("The largest of these five numbers is " + largest + ".");
        System.out.println("The smallest of these five numbers is " + smallest + ".");
        
    }
    
}
