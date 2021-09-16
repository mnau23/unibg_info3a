object Test {

  // check if number is even (1) or not (0)
  def even1(n: Int): Int = {
    if(n%2 == 0)
      return 1
    else
      return 0
  }

  // check if number is even > return a boolean
  def even2(n: Int): Boolean = {
    if(n%2 == 0)
      return true
    else
      return false
  }

  // For
  def countEvens_for(list: List[Int]): Int = {
    var sum = 0
    for(i <- list)
      sum += even1(i)
    sum
  }

  // ForEach
  def countEvens_foreach(list: List[Int]): Int = {
    var sum = 0
    list.foreach(sum += even1(_))
    sum
  }

  // Recursion
  def countEvens_R(list: List[Int]): Int = {
    if(list.isEmpty)
      return 0
    even1(list.head) + countEvens_R(list.tail)
  }

  // FoldLeft
  def countEvens_fold(list: List[Int]): Int = list.foldLeft(0)((x, y) => x + even1(y))

  // Filter
  def countEvens_filter(list: List[Int]): Int = list.filter(even2(_)).size

  // HOF
  def countEvens1(p: (Int => Boolean)): List[Int] => Int = {
    def inner(list: List[Int]): Int = {
      list.filter(p).map(_ => 1).sum
    }
    inner
  }

  def countEvens2(list: List[Int]): Int = {
    countEvens1((a: Int) => a%2 == 0)(list)
  }

  // Main
  def main(args: Array[String]) {
    var nums = List(2, 3, 4, 5, 6)
    println("--- Begin ---")
    println(nums)
    println
    
    println("Even numbers in list (for): " + countEvens_for(nums))
    println("Even numbers in list (foreach): " + countEvens_foreach(nums))
    println("Even numbers in list (recursion): " + countEvens_R(nums))
    println("Even numbers in list (foldLeft): " + countEvens_fold(nums))
    println("Even numbers in list (filter): " + countEvens_filter(nums))

    println
    
    println("Even numbers in list (hof): " + countEvens1(even2)(nums))
    println("Even numbers in list: " + countEvens2(nums))
  }
}