/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject7;

/**
 *
 * @author shengzhang0830
 */

public class InvalidCustomerException extends Exception
{
    String invalidInput;
    
    InvalidCustomerException()
    {
        super();
    }
    
    InvalidCustomerException(String s)
    {
        invalidInput = s;
    }
    
    @Override
    public String getMessage()
    {
        return "Invalid SSN " + invalidInput;
    }
    
}
