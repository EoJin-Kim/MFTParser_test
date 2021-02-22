// MFTParser.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "stdafx.h"


// 현재 바이트 읽을때 offset 이도시 현재 위치기준으로 이동 후 읽는다. 
int _tmain()
{
    //TCHAR driveName[] = TEXT("\\\\.\\PhysicalDrive0");

    TCHAR driveName[] = TEXT("\\\\.\\C:");
    

    UCHAR buf[VBR_SIZE] = { 0, };
    
    MFT_Parser* myDrive = new MFT_Parser(driveName);

    //myDrive->Test();
    //myDrive->OpenDrive();
    myDrive->ReadVBR();
    //myDrive->Read512Byte(buf);
    //NTFS_VBR *myNTFSVBR = new NTFS_VBR;
    //myNTFSVBR = (NTFS_VBR*)buf;
    //_tprintf(TEXT("Jump Command : %x \n"), *(myNTFSVBR->JumpCommand));
    //_tprintf(TEXT("Jump Command : %s \n"), myNTFSVBR->OEM_ID);
    //_tprintf(TEXT("VBR Struct Size : %d \n"), sizeof(*myNTFSVBR));
    _tprintf(TEXT("JumpCommand Size : %d \n"), sizeof(myDrive->myNTFSVBR->JumpCommand));

   myDrive->CloseDrive();


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
