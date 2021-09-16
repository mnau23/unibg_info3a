object Test {

  def neutralMult(a: Int, n: Int): Boolean = {
    if(a*n == a)
      return true
    else
      return false
  }

  def neutralSum(a: Int, b: Int): Boolean =
    neutral((a, b) => if (a + b == a) true else false)(a, b)
  
  // HOF
  def neutralMult2(a: Int, n: Int): Boolean =
    neutral(neutralMult)(a, n)
  
  def neutral(f: (Int, Int) => Boolean): (Int, Int) => Boolean = {
    def inner(a: Int, n: Int): Boolean =
      f(a, n)  // Function
    inner
  }

  // Main
  def main(args: Array[String]) {
    println("10*1, is neutral: " + neutralMult(10, 1))
    println("10*2, is neutral: " + neutralMult(10, 2))
    println("10*0, is neutral: " + neutralMult(10, 0))

    println

    println("10*1, is neutral: " + neutralMult2(10, 1))
    println("10*2, is neutral: " + neutralMult2(10, 2))
    println("10*0, is neutral: " + neutralMult2(10, 0))

    println

    println("10*1, is neutral: " + neutralSum(10, 1))
    println("10*2, is neutral: " + neutralSum(10, 2))
    println("10*0, is neutral: " + neutralSum(10, 0))
  }
}