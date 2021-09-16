object Test {

  // check if number is positive > return it if so
  def isPos(n: Int): Int =
    if(n > 0) n else 0

  // check if number is positive > return boolean
  def isPosBool(n: Int): Boolean =
    if(n > 0) true else false

  // For
  def sumGreaterThan0_for(list: List[Int]): Int = {
    var sum = 0
    for(i <- list)
      sum += isPos(i)
    sum
  }

  // ForEach
  def sumGreaterThan0_foreach(list: List[Int]): Int = {
    var sum = 0
    list.foreach(sum += isPos(_))
    sum
  }

  // Recursion
  def sumGreaterThan0_R(list: List[Int]): Int = {
    if(list.isEmpty)
      return 0

    if(list.head > 0)
      list.head + sumGreaterThan0_R(list.tail)
    else
      sumGreaterThan0_R(list.tail)
  }

  // Tail recursion
  def sumGreaterThan0_TR(list: List[Int], sum: Int): Int = {
    if(list.isEmpty)
      return sum

    if(list.head > 0)
      sumGreaterThan0_TR(list.tail, sum + list.head)
    else
      sumGreaterThan0_TR(list.tail, sum)
  }

  def sumGreaterThan0_TR_Call(list: List[Int]): Int =
    sumGreaterThan0_TR(list, 0)

  // Filter
  def sumGreaterThan0_filter(list: List[Int]): Int =
    list.filter(isPos(_) > 0).sum

  // FoldLeft
  def sumGreaterThan0_foldLeft(list: List[Int]): Int =
    list.foldLeft(0)((x, y) => x + isPos(y))

  // Map
  def sumGreaterThan0_map(list: List[Int]): Int =
    list.map(num => if (num > 0) num else 0).sum

  // HOF
  def sumGreaterThan0_hof(f: (Int => Boolean)): List[Int] => Int = {
    def inner(list: List[Int]): Int =
      list.filter(f(_)).sum
    inner
  }

  // Count number of positive elements in list
  def countPosElem(list: List[Int]): Int =
    list.filter(x => x > 0).map(x => 1).sum
    // Same result as: list.count(x => x > 0)

  // Main
  def main(args: Array[String]) {
    var example = List.range(-5, 5)

    println("--- Begin ---")
    println(example)
    println
    
    println("Sum (for): " + sumGreaterThan0_for(example))
    println("Sum (foreach): " + sumGreaterThan0_foreach(example))
    println("Sum (recursion): " + sumGreaterThan0_R(example))
    println("Sum (tail recursion): " + sumGreaterThan0_TR_Call(example))
    println

    println("Sum (filter): " + sumGreaterThan0_filter(example))
    println("Sum (foldLeft): " + sumGreaterThan0_foldLeft(example))
    println("Sum (map): " + sumGreaterThan0_map(example))
    println("Sum (hof): " + sumGreaterThan0_hof(isPosBool)(example))
    println
    
    println("Positive elements: " + countPosElem(example))
  }
}