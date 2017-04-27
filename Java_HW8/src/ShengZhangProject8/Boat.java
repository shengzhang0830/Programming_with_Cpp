/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ShengZhangProject8;

/**
 *
 * @author shengzhang0830
 */
public class Boat {
    private String name;
    private float speed;
    private float angle;
    private boolean power;
    

    // Default constructor
    public Boat()
    {
        name = "";
        power = false;
        speed = 0;
    }
    
    // Constructor
    public Boat(String newName)
    {
        name = newName;
        power = false;
        speed = 0;
    }
    
    // getName is an accessor that returns the name of the Boat
    public String getName()
    {
        return name;
    }
    
    // powerUp turns on the power of the Boat and prints the current direction to the screen
    public void powerUp()
    {
        power = true;
        System.out.println(name + " is pointing in the direction of " + angle + " deg.");
    }
    
    // powerOff turns down the power of the Boat and prints the current direction to the screen
    public void powerOff()
    {
        power = false;
        System.out.println(name + " is powered off.");
    }

    // speedUp increases the boat's speed by 2 and prints the current direction to the screen if the boat's power is curently on
    public void speedUp()
    {
        if (power)
        {
            speed = speed + 2;
            System.out.println(name + " is  moving in " + angle + " deg angle at the speed of " + speed + " mph.");
        }
        else
        {
            System.out.println("The boat is not powered up yet.");
        }
    }

    // slowDown decreases the boat's speed by 2 and prints the current direction to the screen if the boat's power is curently on    
        public void slowDown()
    {
        if (power)
        {
            if(speed < 2)
            {
                System.out.println("Speed is already too low.");
            }
            else
            {
                speed = speed - 2;
                System.out.println(name + " is  moving in " + angle + " deg angle at the speed of " + speed + " mph.");
            }   
        }
        else
        {
            System.out.println("The boat is not powered up yet.");
        }
    }

    // turnLeft turns the boat's direction to the left by 5 degrees and prints the current direction to the screen if the boat is curently on
    public void turnLeft()
    {
        if (power)
        {
            angle = (angle + 355) % 360;
            System.out.println(name + " is  in " + angle + " deg angle.");
        }
        else
        {
            System.out.println("The boat is not powered up yet.");
        }
    }
    
    // turnRight turns the boat's direction to the right by 5 degrees and prints the current direction to the screen if the boat is curently on
    public void turnRight()
    {
        if (power)
        {
            angle = (angle + 5) % 360;
            System.out.println(name + " is  in " + angle + " deg angle.");
        }
        else
        {
            System.out.println("The boat is not powered up yet.");
        }
    }        
        
        

        
}
