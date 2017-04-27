/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhang;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author shengzhang0830
 */
public class Maze 
{
    public static final int maxRow = 20;
    public static final int maxCol = 50;
    public static char[][] maze;
    

    // Create a new maze (gameboard) from a file
    public static void create(String filename) throws FileNotFoundException
    {
        maze = new char[maxRow][maxCol];
        
        File inputFile = new File(filename);
        Scanner in = new Scanner(inputFile);
        
        int row = 0;
        while (in.hasNextLine())
        {
                String line = in.nextLine();
                for (int i=0; i<maxCol;i++)
                {
                    maze[row][i] = line.charAt(i);
                }
                row ++;
        }
        in.close();
    }

    // Display the maze
    public static void display()
    {
        for(int i=0; i<maxRow; i++)
        {
            for(int j=0; j<maxCol; j++)
            {
                System.out.print(maze[i][j]);
            }
            System.out.println();
        }
    }
    
    // Check the validity of the location to make sure it is not out of boundary
    public static boolean locationValid(int row, int col)
    {
        if (row < 0 || col < 0  || row >= maxRow || col >= maxCol)
        {
            System.out.println("The location you entered is not valid. ");
            return false;
        }
        else
        {
            return true;
        }
    }
    
    // Check the availability of a position in the maze
    public static boolean available(int row, int col)
    {
        if (!locationValid(row,col))
        {
            return false;
        }
        if (maze[row][col] == ' ')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Check whether a given location has nuts
    public static boolean hasNut(int row, int col)
    {
        if (maze[row][col]=='A' || maze[row][col]=='P' || maze[row][col]=='C' )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
