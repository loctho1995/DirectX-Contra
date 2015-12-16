#pragma once
#include "Object.h"
#include <vector>

class QuadTree
{
public:
	QuadTree(int level, RectF bounds )
		:
		bounds(bounds),
		level(level)

	{
		subNodes =  new QuadTree*[4];
		for (int i = 0; i < 4; i++)
		{
			subNodes[i] = NULL;
		}
	}
	~QuadTree()
	{
		for (int i = 0; i < 4; i++)
		{
			if(subNodes[i] != NULL)
			{
				delete subNodes[i];
				subNodes[i] = NULL;
			}
		}
		delete []subNodes;
	}
	QuadTree()
	{}
	//
	void split()
	{
		RectF  r [4];
		float width = bounds.width / 2;
		float height = bounds.height / 2;
		// bounds of subNode 1
		r[ 0 ].x = bounds.x;
		r[ 0 ].y = bounds.y;
		r[ 0 ].height = height;
		r[ 0 ].width = width;

		// bounds of subNode 2
		r[ 1 ].x = bounds.x + width;
		r[ 1 ].y = bounds.y;
		r[ 1 ].height = height;
		r[ 1 ].width = width;

		// bounds of subNode 3
		r[ 2 ].x = bounds.x + width;
		r[ 2 ].y = bounds.y + height;
		r[ 2 ].height = height;
		r[ 2 ].width = width;

		// bounds of subNode 4
		r[ 3 ].x = bounds.x;
		r[ 3 ].y = bounds.y + height;
		r[ 3 ].height = height;
		r[ 3 ].width = width;
		for (int i = 0; i < 4; i++)
		{
			subNodes[i] = new QuadTree(level + 1, r[i]);
		}
	}
	void clear()
	{
		if(RectFs.size() > 0)
		{
			RectFs.clear();
		}

		if(Objects.size() > 0)
		{
			Objects.clear();
		}
		if(cRectFs.size() > 0)
		{
			cRectFs.clear();
		}
		
			for (int i = 0; i < 4; i++)
			{
				if(subNodes[i] != NULL)
				{
					subNodes[i] ->clear();
					delete subNodes[i];
					subNodes[i] = NULL;
				}
			}
		
	}
	//
	int getIndex(RectF object)
	{
		int index = -1;
		bool isOnTop;
		bool isOnLeft;
		bool isOnRight;
		bool isOnBottom;

		float horizontalMiddleLine = bounds.y + bounds.height / 2;
		float verticalMidLine = bounds.x + bounds.width / 2;


		isOnTop = ( object.y + object.height < horizontalMiddleLine);
		isOnLeft = ( object.x + object.width < verticalMidLine);
		isOnRight = ( object.x > verticalMidLine);
		isOnBottom = ( object.y > horizontalMiddleLine);
		if( isOnTop && isOnLeft )
		{
			index = 0;
		}
		if( isOnTop && isOnRight)
		{
			index = 1;
		}
		if( isOnBottom && isOnRight)
		{
			index = 2;
		}
		if( isOnBottom && isOnLeft)
		{
			index = 3;
		}
		return index;
	}
	void insert(RectF object)
	{

		int index = getIndex (object);
		if(subNodes [ 0 ] != NULL) // check whether this node has a subNode
		{
			if(index != -1)
			{
				subNodes [ index ] -> insert(object);
				return;
			}	
		}





		if( index == -1 )
		{
			RectFs.push_back(object);

		}
		else
		{
			if(subNodes [ 0 ] == NULL)
			{
				split();
			}
			subNodes[index] ->insert(object);
		}




		//RectFs.push_back(object);
		//if ( RectFs.size() == 1 )
		//{

		//}
		//else
		//{
		//	
		//	for (int i = 0; i < RectFs.size(); i++)
		//	{
		//		int tempIndex = getIndex(RectFs[i] );
		//		if( tempIndex != -1 )
		//		{
		//			if( subNodes [0 ] == NULL )
		//			{
		//				split();
		//			}

		//			subNodes[tempIndex] -> insert(RectFs[i]);
		//			
		//			RectFs.erase( RectFs.begin() + i );
		//			//RectFs.
		//		}
		//	}
		//}
		
	}
	void getAllSubObject(std::vector <RectF >& returnList)
	{
		for (int i = 0; i < RectFs.size(); i++)
		{
			returnList.push_back(RectFs[i]);
		}
		if(subNodes[0] != NULL )
		{
			for (int i = 0; i < 4; i++)
			{
				subNodes[i] -> getAllSubObject(returnList);
			}
		}
		

	}
	void getObjectlist(std::vector <RectF >& returnList, RectF object)
	{
		int index = getIndex(object);
		if( index != -1 ) 
		{
			if(subNodes [ 0 ] != NULL)
			{
				subNodes[ index] -> getObjectlist(returnList, object);
			}

			for( std::vector<RectF>:: iterator i = RectFs.begin(); i != RectFs.end(); i++)
			{
				returnList.push_back(*i);
			}	

		}
		else
		{
			getAllSubObject(returnList);
		}
	}
	//
	int getIndex(CollisionRectF object)
	{
		int index = -1;
		bool isOnTop;
		bool isOnLeft;
		bool isOnRight;
		bool isOnBottom;

		float horizontalMiddleLine = bounds.y + bounds.height / 2;
		float verticalMidLine = bounds.x + bounds.width / 2;


		isOnTop = ( object . rect.y + object . rect.height < horizontalMiddleLine);
		isOnLeft = ( object . rect.x + object . rect.width < verticalMidLine);
		isOnRight = ( object . rect.x > verticalMidLine);
		isOnBottom = ( object . rect.y > horizontalMiddleLine);
		if( isOnTop && isOnLeft )
		{
			index = 0;
		}
		if( isOnTop && isOnRight)
		{
			index = 1;
		}
		if( isOnBottom && isOnRight)
		{
			index = 2;
		}
		if( isOnBottom && isOnLeft)
		{
			index = 3;
		}
		return index;
	}
	void insert(CollisionRectF object)
	{
		int index = getIndex (object);
		if(subNodes [ 0 ] != NULL) // check whether this node has a subNode
		{
			if(index != -1)
			{
				subNodes [ index ] -> insert(object);
				return;
			}	
		}

		if( index == -1 )
		{
			cRectFs.push_back(object);

		}
		else
		{
			if(subNodes [ 0 ] == NULL)
			{
				split();
			}
			subNodes[index] ->insert(object);
		}




		//RectFs.push_back(object);
		//if ( RectFs.size() == 1 )
		//{

		//}
		//else
		//{
		//	
		//	for (int i = 0; i < RectFs.size(); i++)
		//	{
		//		int tempIndex = getIndex(RectFs[i] );
		//		if( tempIndex != -1 )
		//		{
		//			if( subNodes [0 ] == NULL )
		//			{
		//				split();
		//			}

		//			subNodes[tempIndex] -> insert(RectFs[i]);
		//			
		//			RectFs.erase( RectFs.begin() + i );
		//			//RectFs.
		//		}
		//	}
		//}
		
	}
	void getAllSubObject(std :: vector < CollisionRectF >& returnList)
	{
		for (int i = 0; i < cRectFs.size(); i++)
		{
			returnList.push_back(cRectFs[i]);
		}
		if(subNodes[0] != NULL )
		{
			for (int i = 0; i < 4; i++)
			{
				subNodes[i] -> getAllSubObject(returnList);
			}
		}
	}
	void getObjectlist(std :: vector < CollisionRectF >& returnList, RectF object)
	{
		int index = getIndex(object);
		if( index != -1 ) 
		{
			if(subNodes [ 0 ] != NULL)
			{
				subNodes[ index] -> getObjectlist(returnList, object);
			}

			for( std::vector<CollisionRectF >:: iterator i = cRectFs.begin(); i != cRectFs.end(); i++)
			{
				returnList.push_back(*i);
			}	

		}
		else
		{
			getAllSubObject(returnList);
		}
	}
	//
	int getIndex(Object* object)
	{
		int index = -1;
		bool isOnTop;
		bool isOnLeft;
		bool isOnRight;
		bool isOnBottom;

		float horizontalMiddleLine = bounds.y + bounds.height / 2;
		float verticalMidLine = bounds.x + bounds.width / 2;


		isOnTop = ( object -> body.y + object -> body.height < horizontalMiddleLine);
		isOnLeft = ( object -> body.x + object -> body.width < verticalMidLine);
		isOnRight = ( object -> body.x > verticalMidLine);
		isOnBottom = ( object -> body.y > horizontalMiddleLine);
		if( isOnTop && isOnLeft )
		{
			index = 0;
		}
		if( isOnTop && isOnRight)
		{
			index = 1;
		}
		if( isOnBottom && isOnRight)
		{
			index = 2;
		}
		if( isOnBottom && isOnLeft)
		{
			index = 3;
		}
		return index;
	}
	void insert(Object* object)
	{
		int index = getIndex (object);
		if(subNodes [ 0 ] != NULL) // check whether this node has a subNode
		{
			if(index != -1)
			{
				subNodes [ index ] -> insert(object);
				return;
			}	
		}

		if( index == -1 )
		{
			Objects.push_back(object);

		}
		else
		{
			if(subNodes [ 0 ] == NULL)
			{
				split();
			}
			subNodes[index] ->insert(object);
		}




		//RectFs.push_back(object);
		//if ( RectFs.size() == 1 )
		//{

		//}
		//else
		//{
		//	
		//	for (int i = 0; i < RectFs.size(); i++)
		//	{
		//		int tempIndex = getIndex(RectFs[i] );
		//		if( tempIndex != -1 )
		//		{
		//			if( subNodes [0 ] == NULL )
		//			{
		//				split();
		//			}

		//			subNodes[tempIndex] -> insert(RectFs[i]);
		//			
		//			RectFs.erase( RectFs.begin() + i );
		//			//RectFs.
		//		}
		//	}
		//}
		
	}
	void getAllSubObject(std :: vector < Object* >& returnList)
	{
		for (int i = 0; i < Objects.size(); i++)
		{
			returnList.push_back(Objects[i]);
		}
		if(subNodes[0] != NULL )
		{
			for (int i = 0; i < 4; i++)
			{
				subNodes[i] -> getAllSubObject(returnList);
			}
		}
	}
	void getObjectlist(std :: vector < Object* >& returnList, RectF object)
	{
		int index = getIndex(object);
		if( index != -1 ) 
		{
			if(subNodes [ 0 ] != NULL)
			{
				subNodes[ index] -> getObjectlist(returnList, object);
			}

			for( std::vector<Object* >:: iterator i = Objects.begin(); i != Objects.end(); i++)
			{
				returnList.push_back(*i);
			}	

		}
		else
		{
			getAllSubObject(returnList);
		}
	}

private:
	
	int level;
	std :: vector < RectF > RectFs;
	std :: vector < Object* > Objects;
	std :: vector < CollisionRectF > cRectFs;
	RectF bounds;
	QuadTree**  subNodes;


};
