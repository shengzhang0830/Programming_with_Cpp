/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject5;

/**
 *
 * @author shengzhang0830
 */

// CheckingAccount inherits BankAccount
public class CheckingAccount extends BankAccount 
{
    private double interestRate = 0.02;
    
    public CheckingAccount(String first, String last, String social, double initial)
    {
        super(first, last, social, initial);
    }
    
    public void applyInterest()
    {
        if(balance > 10000)
        {
            balance = balance + interestRate * (balance - 10000);
        }
    }
    
}
