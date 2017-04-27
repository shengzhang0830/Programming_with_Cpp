/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhang;

import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author shengzhang0830
 */
public class HungrySquirrelGame 
{

    public static void main(String[] args) throws FileNotFoundException     
    {
        // To construct the maze
        Maze.create("maze.txt");
        Maze.display();
        
        // To create a squirrel
        Squirrel sq = new Squirrel();
        Maze.display();

        
        // To create 5 almonds / peanuts
        Nut[]allNuts = new Nut[Nut.totalNuts];
        for(int i=0; i< Nut.totalNuts; i++)
        {
            int randNut = (int)(Math.random()*2);
            if (randNut == 0)
            {
                allNuts[i] = new Almond();
                allNuts[i].create();
            }
            if (randNut == 1)
            {
                allNuts[i] = new Peanut();
                allNuts[i].create();
            }            
        }
        
        // To create 5 poisonous cashews
        Nut[]allCashews = new Nut[Nut.totalNuts];
        for (int i=0; i< Nut.totalNuts; i++)
        {
                allNuts[i] = new PoisonousCashew();
                allNuts[i].create();
        }
        
        Maze.display();
       
        // Ask for user input as moves on the gameboard, until the game is over
        while (sq.getTotalNutsEaten() < Nut.totalNuts && sq.getPointsColelcted() >= 0)
        {
            Scanner in = new Scanner(System.in);
            System.out.println("Enter commands u, d, r, l to move up, down, right, or left: ");
            String direction = in.nextLine().toLowerCase();
                    
            if (direction.length()!=1)
            {
                System.out.println("Please enter a valid direction.");
            }
            else
            {
                sq.move(direction.charAt(0));
            }
        }
        
        if (sq.getTotalNutsEaten() == Nut.totalNuts)
        {
            System.out.println("Squirrel successfully collected all the nuts. Total points: " + sq.getPointsColelcted());
            System.out.println("Thank you for playing this game.");            
        }
        
        if (sq.getPointsColelcted() < 0)
        {
            System.out.println("The squirrel dies. Game over!!");
        }
    }

}
