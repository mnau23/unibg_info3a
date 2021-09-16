package intro

object passbyname {

  def f(x: Int, y: Int) = x + x                   //> f: (x: Int, y: Int)Int

  def f0(x: => Int, y: => Int) = x + x            //> f0: (x: => Int, y: => Int)Int

  println("Welcome to the Scala worksheet")       //> Welcome to the Scala worksheet

	//f(4,5)
	f0(4,5)                                   //> res0: Int = 8
	
	//f(6+7,3)
	f0(6+7,3)                                 //> res1: Int = 26
}