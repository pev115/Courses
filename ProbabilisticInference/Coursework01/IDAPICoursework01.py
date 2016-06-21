#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Coursework in Python 
from IDAPICourseworkLibrary import *
from numpy import *
#
# Coursework 1 begins here
#
# Function to compute the prior distribution of the variable root from the data set
def Prior(theData, root, noStates):
    prior = zeros((noStates[root]), float )
# Coursework 1 task 1 should be inserted here
    
#Calculate the prior distribution : for each state of the variable
#find the number of occurances of this state in the data points and 
#divide by the total number of data points
    for i in range(noStates[root]) :
      prior[i] = list(theData[:,root]).count(i)/float(theData.shape[0])
    
# end of Coursework 1 task 1
    return prior
  
  
  
# Function to compute a CPT with parent node varP and xchild node varC from the data array
# it is assumed that the states are designated by consecutive integers starting with 0
def CPT(theData, varC, varP, noStates):
  cPT = zeros((noStates[varC], noStates[varP]), float )
# Coursework 1 task 2 should be inserte4d here
 
#for each of the states of the parent and the child variables find P(VarC|VarP) = N_candp/N_p 
#where N_x is the number of datapoints with state x 
  for i in range(noStates[varP]) :
     for j in range(noStates[varC]):
       #Find the number of occurences of state i of varP
	N_p = list(theData[:, varP]).count(i)
	# find the number of occurences of both states i and j of varP and varC
	N_candp = list(theData[theData[:,varP]==i][:,varC]).count(j)
	#divide to get the conditional probability
	cPT[j,i] = float(N_candp)/float(N_p)  
   
# end of coursework 1 task 2
  return cPT
  
  
  
# Function to calculate the joint probability table of two variables in the data set
def JPT(theData, varRow, varCol, noStates):
    jPT = zeros((noStates[varRow], noStates[varCol]), float )
#Coursework 1 task 3 should be inserted here 

#find the number of datapoints by looking at the number of rows
    dtpts = float(theData.shape[0])
#for each of the states of the two variables we want to have the JPT
    for i in range(noStates[varCol]):
      for j in range(noStates[varRow]):
	#find the number of datapoints having both those states
	#list all the datapoints in column varRow that are in a row where 
	#varCol = i and count the number of occurances of j
	N_rowandcol = list(theData[theData[:,varCol]==i][:,varRow]).count(j)
	#find the joint probability P(varRow & varCol) = N_rowandcol/dtpts
	jPT[j,i] = float(N_rowandcol)/float(dtpts)
    
# end of coursework 1 task 3
    return jPT
  
  
  
  
  
#
# Function to convert a joint probability table to a conditional probability table
def JPT2CPT(aJPT):
#Coursework 1 task 4 should be inserted here 

  for j in range( aJPT.shape[1]):
    #sum the values in the colum : eliminate the corresponding variable
    p_b = sum(aJPT[:,j])
    for i in range( aJPT.shape[0]):
    # Get the conditional probability : P(A|B) = P(A&B)/P(B) .
	aJPT[i,j] =  aJPT[i,j]/float(p_b)     
	   
   
# coursework 1 taks 4 ends here
    return aJPT

#
# Function to query a naive Bayesian network
def Query(theQuery, naiveBayes): 
  rootPdf = zeros((naiveBayes[0].shape[0]), float)
# Coursework 1 task 5 should be inserted here

  for i in range(rootPdf.shape[0]): #for each of the states of the root
    #initialise the likelyhood information to 1
    likelyhood_info = float(1.0)
    for j in range(len(naiveBayes)-1): # for each of the CPT's
      #Calculate the likelyhood: the product of the conditional probabilities 
      likelyhood_info = likelyhood_info* float(naiveBayes[j+1][theQuery[j],i])
    #update the root probabilty for each state : P(R) = Prior*likelyhood_info
    rootPdf[i] = float(naiveBayes[0][i])*likelyhood_info
  
#Normalise 
  Sum =float(sum(rootPdf))
#if the sum is 0, return the distribution as is
  if Sum == 0 :
     return rootPdf

#if sum != 0 divide each element by the  sum to normalise the distribution and return   
  for k in range(len(rootPdf)):
    rootPdf[k] = rootPdf[k]/Sum
   
# end of coursework 1 task 5
  return rootPdf
  
  
#
# End of Coursework 1
#


#
# main program part for Coursework 1
#
noVariables, noRoots, noStates, noDataPoints, datain = ReadFile("Neurones.txt")
theData = array(datain)
AppendString("IDAPIResults01.txt","Coursework One Results by Pierre Eugene Valassakis (pev115, 00644379)")
AppendString("IDAPIResults01.txt","") #blank line
AppendString("IDAPIResults01.txt","The prior probability of node 0")
prior = Prior(theData, 0, noStates)
AppendList("IDAPIResults01.txt", prior)
#
# continue as described
#
#

#Question 1.2
#Calculate  P(2|0) and display it on the results file
AppendString("IDAPIResults01.txt","The conditional probability matrix P(2|0) calculated from the data")
cpt = CPT(theData, 2,0,noStates)
AppendArray("IDAPIResults01.txt", cpt)

#Question 1.3
#Calculate the joint probability matrix P(2&0) and display it on the results file
AppendString("IDAPIResults01.txt", " The joint  probability matrix P(2&0) calculated from the data")
jpt = JPT(theData,2,0,noStates)
AppendArray("IDAPIResults01.txt", jpt)

#Question 1.4
#Calculate the conditional probability matrix P(2|0) from P(2&0) and display it on the results file
AppendString("IDAPIResults01.txt", " The conditional probability matrix P(2|0) calculated from the joint probability matrix P(2&0)")
jpt2cpt = JPT2CPT(jpt)
AppendArray("IDAPIResults01.txt", jpt2cpt)

#Question 1.5

#Calculate the conditional probability tables for the different variables
cpt1= CPT(theData, 1,0, noStates)
cpt2= CPT(theData, 2,0, noStates)
cpt3 = CPT(theData, 3,0, noStates)
cpt4 = CPT(theData, 4,0, noStates)
cpt5 = CPT(theData, 5,0, noStates)

#Query the network with the queries [4,0,0,0,5] and [6,5,2,5,5] and display the results in the results file

AppendString("IDAPIResults01.txt", "The results of queries [4,0,0,0,5] and [6,5,2,5,5] on the naive network")
AppendString("IDAPIResults01.txt", "For query [4,0,0,0,5] :")
queryresult1 = Query([4,0,0,0,5],[prior, cpt1,cpt2,cpt3,cpt4,cpt5] )
AppendList("IDAPIResults01.txt",queryresult1)

AppendString("IDAPIResults01.txt", "For query [6,5,2,5,5] :")
queryresult2 = Query([6,5,2,5,5],[prior, cpt1,cpt2,cpt3,cpt4,cpt5] )
AppendList("IDAPIResults01.txt",queryresult2)


