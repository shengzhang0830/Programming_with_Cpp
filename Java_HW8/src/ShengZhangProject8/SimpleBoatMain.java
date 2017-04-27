/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ShengZhangProject8;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author shengzhang0830
 */
public class SimpleBoatMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException
    {        
        
        // Read in the names of all the boats from a file
        File inputFile = new File("boats.txt");
        Scanner in = new Scanner(inputFile);
        int lineNumber = 0;
        
        final int LENGTH = 100;
        Boat[] boats = new Boat[LENGTH];
 
        for(int i = 0; i < LENGTH; i++)
        {
            if (in.hasNextLine())
            {
                String name = in.nextLine();
                boats[i] = new Boat(name);
            }
            else
            {
                lineNumber = i;
                break;
            }
        }
        
        
        System.out.println("Please enter your command, or enter 'quit'.");
        Scanner keyboard = new Scanner(System.in);
        
        // Reads in user commands line by line
        while(keyboard.hasNextLine())
        {
            String input = keyboard.nextLine();
            
            if (input.equalsIgnoreCase("quit"))
            {
                break;
            }
            
            String[] token = input.split(",");
            
            if (token.length != 2)
            {
                System.out.println("Invalid input, please try again.");
                continue;
            }
            
            String name = token[0].trim();
            String command = token[1].trim();            
        
            boolean nameFound = false;
            
            for (int i = 0; i < lineNumber; i++)
            {
                if (boats[i].getName().equals(name))
                {
                    nameFound = true;
                    
                    if ("power on".equals(command))
                    {
                        boats[i].powerUp();
                    }
                    else if ("power off".equals(command))
                    {
                        boats[i].powerOff();
                    }
                    else if ("speed up".equals(command))
                    {
                        boats[i].speedUp();
                    }
                    else if ("slow down".equals(command))
                    {
                        boats[i].slowDown();
                    }
                    else if ("turn left".equals(command))
                    {
                        boats[i].turnLeft();
                    }
                    else if ("turn right".equals(command))
                    {
                        boats[i].turnRight();
                    }
                    else
                    {
                        System.out.println("Invalid input, please try again.");
                    }
                }                
            }
            
            if(!nameFound)
            {
                System.out.println("The boat does not exist in the file.");
            }
            
        }
        
        keyboard.close();

    }
    
}
