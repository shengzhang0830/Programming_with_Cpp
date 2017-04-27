/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package shengzhangproject5;
import java.util.Arrays;
import java.util.Random;



/**
 *
 * @author shengzhang0830
 */
public class BankAccount 
{

    private Customer customer = new Customer();
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

        // Check the validity of ssn
        if(social.matches("1233-45-6789"))
        {
            System.out.println("Successfully created account for " + first + last + ". Inavlid SSN!");
        }
        
        System.out.print("Successfully created account for " + first + last + " Account Number ");
        printIntArray(accountNumber);
        System.out.println("");
        System.out.println(customer.getName() + ", Balance $" + balance);
    }
    
    // Deposit adds the input to the current balance
    public void deposit(double deposit)
    {
        balance = balance + deposit;
        System.out.println(customer.getName() + " deposited $" + deposit + ". Current balance $" + balance);
    }
    
    // Withdraw deducts the input from the current balance, unless the result is less than 0
    public void withdraw(double withdrewal)
    {
        if(withdrewal > balance)
        {
            System.out.println("Unable to withdraw $" + withdrewal + " for " + customer.getName() + " due to insufficient funds");
        }
        else
        {    
            balance = balance - withdrewal;
            System.out.println(customer.getName() + " withdrew $" + withdrewal + ". Current balance $" + balance);
        }
    }
    
    // applyInterest applies the interest rate to the current balance
    public void applyInterest()
    {
        balance = balance * (1 + interestRate);
    }
    
    // Check balance prints out the current balance and the customer's name
    public void checkBalance()
    {
        System.out.println(customer.getName() + ", Balance $" + balance);
    }
    
}
