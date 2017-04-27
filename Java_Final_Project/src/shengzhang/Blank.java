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

// Blank (blank space in the map) inherits from the Entity abstact class
public class Blank extends Entity
{
    
    protected static int nutritionPoints = 0;

    public Blank()
    {
        super(' ');
    }
    

    @Override
    public void create() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
