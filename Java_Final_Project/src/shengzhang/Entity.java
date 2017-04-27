/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhang;

/**
 *
 * @author shengzhang0830
 */

// Define an abstract class Entity to represent a position on the gameboard
public abstract class Entity
{
    protected static char symbol;
    protected int row;
    protected int col;
    protected static int nutritionPoints;
    
    // Constructor
    public Entity(char s)
    {
        symbol = s;
    }
    
    abstract public void create();

    // Updates positions and points when the player (@) moves
    public static Entity put(int newRow, int newCol)
    {
        char original = 0;
        
        if (Maze.available(newRow, newCol) || Maze.hasNut(newRow, newCol))
        {
            original = Maze.maze[newRow][newCol];
        }
    

        Maze.maze[newRow][newCol] = '@';

        if (original == ' ')
        {
            Blank b = new Blank();
            nutritionPoints = Blank.nutritionPoints;
            return b;
        }
        else if (original == 'A')
        {
            Almond a = new Almond();
            nutritionPoints = Almond.nutritionPoints;            
            return a;
        }
        else if (original == 'P')
        {
            Peanut p = new Peanut();
            nutritionPoints = Peanut.nutritionPoints;            
            return p;
        }
        else if (original == 'C')
        {
            PoisonousCashew p = new PoisonousCashew();
            nutritionPoints = PoisonousCashew.nutritionPoints;
            return p;
        }
        else if (original == '@')
        {
            Squirrel s = new Squirrel();
            return s;
        }
        else
        {
            Blank b = new Blank();
            nutritionPoints = Blank.nutritionPoints;            
            return b;
        }
    } 
    
    // Removes the object from its old position on the gameboard
    public void remove(int oldRow, int oldCol)
    {
        Maze.maze[oldRow][oldCol] = ' ';
    }
    
}
