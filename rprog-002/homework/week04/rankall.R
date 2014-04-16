rankall <- function(outcome, num = "best") {
  ## Read outcome data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  
  ## Check that state and outcome are valid
  col_num <- -1
  if(outcome == "heart attack"){
    col_num <- 11
  }
  else if(outcome == "heart failure")
  {
    col_num <- 17
  }
  else if(outcome == "pneumonia")
  {
    col_num <- 23
  }
  else
  {
    stop("invalid outcome")
  }
  
  f = as.factor(data$State)
  split(data,f)

  ## For each state, find the hospital of the given rank
  
  func <- function(x){
    x<-x[x[,col_num]!="Not Available",]
    results<-x[order(as.numeric(x[,col_num])),]
    if(num == "best")
      w<-results[1,c(2,7)]
    else if(num == "worst"){
      w<-results[nrow(results),c(2,7)]
    }
    else{
      if(nrow(results)<num){
        w<-data.frame(hospital = "<NA>", state = x[[1,7]],stringsAsFactors = FALSE)
      }
      else{
        w<-results[num,c(2,7)]
      }
    }
    colnames(w)<-c('hospital','state')
    rownames(w)<-x[[1,7]]
    w
  }
  
  result_list <- lapply(l, func)
  
  f2<-as.factor(names(result_list))
  unsplit(result_list,f2)
  
  
  
  ## Return a data frame with the hospital names and the
  ## (abbreviated) state name
  
}