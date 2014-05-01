## week 04 quiz question 02
question02<-function(){
  q02<-read.csv("question02.csv",header=FALSE)
  q02a<-q02[1:190,]
  q02num<-as.numeric(gsub(",","",q02a$V4))
  mean(q02num)
}

question04<-function(){
  q04<-read.csv("question04.csv",header=FALSE)
  q04<-q04[1:190,]
  q04_edu<-read.csv("question04-edu.csv",header=TRUE)
  q4<-merge(q04,q04_edu,by.x="V1",by.y="CountryCode",all=TRUE)
  length(grep("^Fiscal year end: June",q4$Special.Notes))
}

question05<-function(){
  library(quantmod)
  amzn = getSymbols("AMZN",auto.assign=FALSE)
  sampleTimes = index(amzn)
  q5<-as.Date(sampleTimes)
  print(length(which(year(q5)==2012)))
  length(which(year(q5)==2012 & weekdays(q5)=="星期一"))
}