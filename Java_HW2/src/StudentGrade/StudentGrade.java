/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package StudentGrade;

/**
 *
 * @author shengzhang0830
 */
public class StudentGrade {
    
    public static void main(String[] args)
    {
        String letterGrade;
        for(int i = 0; i < 5; i++)
        {
            int grade = (int)(Math.random() * 50) + 50;
            if(grade <= 100 && grade >= 90)
            {
                letterGrade = "A";
            }
            else if(grade < 90 && grade >= 80)
            {
                letterGrade = "B";
            }
            else if(grade < 80 && grade >= 70)
            {
                letterGrade = "C";
            }
            else if(grade < 70 && grade >= 60)
            {
                letterGrade = "D";
            }
            else
            {
                letterGrade = "F";
            }
            System.out.println("Student grade is " + grade + " which is " + letterGrade);
        }
    }
}
