question01<-function(){
  q1<-read.csv("question01.csv",header=TRUE)
  agricultureLogical <-(q1$AGS==6 & q1$ACR==3 & !is.na(q1$AGS) & !is.na(q1$ACR))
  which(agricultureLogical)
}