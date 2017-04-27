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
public class SimpleBoatMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        // Construct a boat
        Boat simpleBoat = new Boat("Destinty");

        // Use the member functions defined in the boat class
        simpleBoat.goFast();
        simpleBoat.goSlow();
        simpleBoat.whereIsTheSail();
        simpleBoat.goFast();
        simpleBoat.whereIsTheSail();
        simpleBoat.goFast();
        
    }
    
}
