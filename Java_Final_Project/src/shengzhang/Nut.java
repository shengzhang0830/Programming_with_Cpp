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

// Nut inherits from the Entity abstract class
public abstract class Nut extends Entity
{
    public static final int totalNuts = 5;
    protected int nutritionPoints;
    protected String name;
    
    public Nut(char n)
    {
        super(n);
    }
    
    public void create()
    {
        int rowRand = (int)(Math.random()*20);
        int colRand = (int)(Math.random()*50);
        boolean valid = false;
        while(!valid)
        {            
            if (Maze.maze[rowRand][colRand] == ' ')
            {
                Maze.maze[rowRand][colRand] = symbol;
                valid = true;
            }
            else
            {
                rowRand = (int)(Math.random()*20);
                colRand = (int)(Math.random()*50);
            }
        }
    }

}
