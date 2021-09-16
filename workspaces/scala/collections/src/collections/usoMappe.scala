package collections

import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer
import java.util.LinkedList

object usoMappe {
  
  def main(args: Array[String]): Unit = {
    ///
    var voti = new HashMap[String, Integer]
    voti += "giovanni" -> 30;
    voti += "urturo" -> 18;    
    println(voti("giovanni"))

    println()
    ///
    var auto = new ListBuffer[String]
    auto += "panda"
    auto += "maserati"
    println(auto)
    println(auto(0))

  }

}