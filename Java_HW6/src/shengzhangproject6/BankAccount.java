/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject6;
import java.util.*;


/**
 *
 * @author shengzhang0830
 */
public abstract class BankAccount implements Comparable<BankAccount>
{
    protected Customer customer = new Customer();
    protected int[] accountNumber;
    protected double balance;
    private double interestRate = 0;
    
    // Helper functions
    public void printIntArray(int[] array)
    {
        for(int i = 0; i < 10; i++)
        {
            System.out.print(array[i]);
        }
    }

    // Default constructor   
    public BankAccount()
    {
        accountNumber = new int[10];
        for(int i = 0; i < 10; i++)
        {
            accountNumber[i] = (int) (Math.random()*10);
        }
        balance = 0;
    }

    // Constructor with first name, last name, ssn, and initial balance
    public BankAccount(String first, String last, String social, double initial)
    {
        customer.changeInfo(first, last, social);
        
        accountNumber = new int[10];
        for(int i = 0; i < 10; i++)
        {
            Random rand = new Random();
            accountNumber[i] = rand.nextInt(9);
        }
        
        balance = initial;

        if(social.matches("1233-45-6789"))
        {
            System.out.println("Successfully created account for " + first + " " + last + ". Inavlid SSN!");
        }
        
        System.out.print("Successfully created account for " + first + " " + last + " Account Number ");
        printIntArray(accountNumber);
        System.out.println("");
    }
    
    

    public void deposit(double deposit)
    {

    }
    
    public void withdraw(double withdrewal)
    {
        
    }
    
    abstract public void applyInterest();
    
    public void checkBalance()
    {

    }
    

    public double getBalance()
    {
        return balance;
    }

    public void print()
    {
        
    }
    
    
    public int compareTo(BankAccount other)
    {
        if(balance > other.balance)
            return -1;
        else if(balance < other.balance)
            return 1;
        else return 0;
    }
    
}


