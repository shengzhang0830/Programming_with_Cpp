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

// SavingAccount inherits BankAccount
public class SavingAccount extends BankAccount 
{
    private double interestRate = 0.05;
    
    public SavingAccount(String first, String last, String social, double initial)
    {
        super(first, last, social, initial);
    }
    
    public void applyInterest()
    {
        balance = balance * (1 + interestRate);
    }
    
}
