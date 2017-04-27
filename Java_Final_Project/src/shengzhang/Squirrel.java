/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhang;

import java.util.Scanner;

/**
 *
 * @author shengzhang0830
 */

// Squirrel inherits the class Entity and implements the Movable interface 
public class Squirrel extends Entity implements Movable
{
    protected int pointsCollected;
    protected int totalNutsEaten;
    private int row;
    private int col;
    
    public Squirrel()
    {
        super('@');
        create();
    }
    
    // Create a squirrel on the gameboard
    @Override
    public void create() throws NumberFormatException
    {
        Scanner in = new Scanner(System.in);
        boolean invalidInput = true;
        
        while(invalidInput)
        {
            int newRow = -1;
            int newCol = -1;
            try
            {
                // Ask the user for the position of the squirrel
                System.out.println("Enter the Squirrel position (row , column): ");
                String input = in.nextLine();

                newRow = Integer.parseInt(input.split(",")[0].trim());
                newCol = Integer.parseInt(input.split(",")[1].trim());
                
                // Check whether the position selected is valid and available
                if (Maze.maze[newRow][newCol] == ' ')
                {
                    row = newRow;
                    col = newCol;
                    super.put(row, col);
                    invalidInput = false;
                    System.out.println("User input accepted.");
                    break;
                }
                else if (!Maze.locationValid(newRow, newCol))
                {
                    System.out.println("Incorrect format, please try again.");
                }
                else if (Maze.locationValid(newRow, newCol) && Maze.maze[newRow][newCol] != ' ')
                {
                    System.out.println("Position not available. Try again.");
                }
            }
            catch (NumberFormatException exception)
            {
                System.out.println("Incorrect format, please try again.");
            }
            catch (ArrayIndexOutOfBoundsException exception)
            {
                System.out.println("Incorrect format, please try again.");                
            }
        }
    }
    
    // Moves the squirrel using put at the new location and remove at the old location
    @Override
    public void move(char direction) 
    {        
        
        if (direction == 'd')
        {
            if (Maze.available(row+1, col) || Maze.hasNut(row+1, col))
            {
                super.put(row+1, col);
                int newPoints = super.nutritionPoints;
                pointsCollected += newPoints;
                
                super.remove(row, col);
                row ++;
                if(newPoints != 0)
                {
                    System.out.println("!!! Squirrel ate a nut and gained " + newPoints + " points. (Total " + pointsCollected + " points)!!!");
                    if(newPoints != -15)
                    {
                        totalNutsEaten ++;
                    }                    
                }
                Maze.display();
            }
            else
            {
                System.out.println("Position not available. Try again!");
            }
        }
        else if (direction == 'u')
        {
            if (Maze.available(row-1, col) || Maze.hasNut(row-1, col))
            {
                int newPoints = super.put(row-1, col).nutritionPoints;
                pointsCollected += newPoints;
                
                super.remove(row, col);
                row --;
                if(newPoints != 0)
                {
                    System.out.println("!!! Squirrel ate a nut and gained " + newPoints + " points. (Total " + pointsCollected + " points)!!!");
                    if(newPoints != -15)
                    {
                        totalNutsEaten ++;
                    }                    
                }
                Maze.display();
            }
            else
            {
                System.out.println("Position not available. Try again!");
            }
        }        
        else if (direction == 'r')
        {
            if (Maze.available(row, col+1) || Maze.hasNut(row, col+1))
            {
                int newPoints = super.put(row, col+1).nutritionPoints;
                pointsCollected += newPoints;
                
                super.remove(row, col);
                col ++;
                
                if(newPoints != 0)
                {
                    System.out.println("!!! Squirrel ate a nut and gained " + newPoints + " points. (Total " + pointsCollected + " points)!!!");
                    
                    if(newPoints != -15)
                    {
                        totalNutsEaten ++;
                    }
                }
                Maze.display();
            }
            else
            {
                System.out.println("Position not available. Try again!");
            }
        }        
        else if (direction == 'l')
        {
            if (Maze.available(row, col-1) || Maze.hasNut(row, col-1))
            {
                int newPoints = super.put(row, col-1).nutritionPoints;
                pointsCollected += newPoints;
                
                super.remove(row, col);
                col --;
                
                if(newPoints!=0)
                {
                    System.out.println("!!! Squirrel ate a nut and gained " + newPoints + " points. (Total " + pointsCollected + " points)!!!");
                    if(newPoints != -15)
                    {
                        totalNutsEaten ++;
                    }                    
                }
                
                Maze.display();
            }
            else
            {
                System.out.println("Position not available. Try again!");
            }
        }
        else
        {
            System.out.println("Invalid input. Try again!");
        }
    
    }

    public int getPointsColelcted()
    {
        return pointsCollected;
    }
        
    public int getTotalNutsEaten()
    {
        return totalNutsEaten;
    }
}
