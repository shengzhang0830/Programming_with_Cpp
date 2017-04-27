/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package boatexamples;

/**
 *
 * @author shengzhang0830
 */
public class Boat {
    private String name;
    private boolean sailPosition;
    private float speed;
    
    // Default constructor
    public Boat()
    {
        name = "";
        sailPosition = false;
        speed = 0;
    }
    
    // Constructor
    public Boat(String newName)
    {
        name = newName;
        sailPosition = false;
        speed = 0;
    }
    
    // goFast increases the speed of the current boat by 10
    public void goFast()
    {
        sailPosition = true;
        speed = speed + 10;
        System.out.println(name + " is  raising the sail at the speed of 10 mph.");
    }
    
    // goSlow decreases the speed of the current boat by 10
    public void goSlow()
    {
        sailPosition = false;
        speed = speed - 5;
        System.out.println(name + " is  lowering the sail at the speed of 5 mph.");
    }

    // whereIsTheSail prints out whether the sail of the boat object is up or down
    public void whereIsTheSail()
    {
        if(sailPosition)
        {
            System.out.println(name + " sail is up.");
        }
        else
        {
            System.out.println(name + " sail is down.");            
        }
        
    }
    
}
