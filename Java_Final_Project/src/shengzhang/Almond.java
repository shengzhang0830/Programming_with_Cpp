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

// Almond inherits from the Nut class
public class Almond extends Nut
{
	// Eating an almond is worth 5 points
    protected static final int nutritionPoints = 5;
    
    public Almond()
    {
        super('A');
    }
    
}
