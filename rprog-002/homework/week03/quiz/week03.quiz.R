# week03 quiz

problem01<-function(){
  library(datasets)
  data(iris)
  mean(iris[iris$Species == "virginica",]$Sepal.Length)
}

problem02<-function(){
  library(datasets)
  data(iris)
  apply(iris[, 1:4], 2, mean)
}

problem03<-function(){
  library(datasets)
  data(mtcars)
}