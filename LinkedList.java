import java.util.*;

class LinkedList {
    Node head;

    class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    // At starting
    public void push(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
        return;
    }

    public void append(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }
        Node last = head;

        while (last.next != null) {
            last = last.next;
        }
        last.next = newNode;
        return;
    }

    public void insertBetween(Node prevNode, int data) {
        if (prevNode == null) {
            System.out.println("Not Possible");
            return;
        }

        Node newNode = new Node(data);
        newNode.next = prevNode.next;
        prevNode.next = newNode;
        return;
    }

    public void printLinkedList() {
        Node node = head;
        while (node != null) {
            System.out.print(node.data + "->");
            node = node.next;
        }
        System.out.println();
        return;
    }

    public Node middleNode(Node head) {
        int c = 0;
        Node temp = head;
        while (temp != null) {
            ++c;
            temp = temp.next;
        }
        c = c / 2;

        while (c > 0) {
            head = head.next;
            --c;
        }
        return head;
    }

    public Node middleNode2(Node head) {

        Node slow = head, fast = head;
        while ((fast != null) && (fast.next != null)) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    // Using inplace
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        ListNode temp = null, tem = list1;
        if (list1.val > list2.val) {
            list1 = list2;
            list2 = temp;
        }

        ListNode res = list1;

        while ((list1 != null) && (list2 != null)) {
            if (list1.val <= list2.val) {
                temp = list1;
                list1 = list1.next;
            } else {
                temp.next = list2;
                temp = list2;
                list2 = list2.next;
                tem = list2;
                list2 = list1;
                list1 = tem;
            }
        }
        temp.next = list2;
        return res;
    }

    // Using Extra Memory
    public ListNode mergeTwoLists2(ListNode list1, ListNode list2) {
        ListNode tail = new ListNode(), head = tail;

        while ((list1 != null) && (list2 != null)) {
            if (list1.val <= list2.val) {
                tail.next = new ListNode(list1.val);
                list1 = list1.next;
            } else {
                tail.next = new ListNode(list2.val);
                list2 = list2.next;
            }
            tail = tail.next;
        }
        while (list1 != null) {
            tail.next = new ListNode(list1.val);
            list1 = list1.next;
            tail = tail.next;
        }
        while (list2 != null) {
            tail.next = new ListNode(list2.val);
            list2 = list2.next;
            tail = tail.next;
        }

        return head.next;
    }

    public ListNode mergeTwoLists5(ListNode list1, ListNode list2) {

        if ((list1 == null)) {
            return list2;
        }
        if ((list2 == null)) {
            return list1;
        }

        if (list1.val <= list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode newNode = new ListNode(0, head);
        ListNode slow = newNode, fast = newNode;

        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }

        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return newNode.next;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0, carry = 0;
        ListNode newNode = new ListNode(), head = newNode;

        while ((l1 != null) || (l2 != null) || (carry != 0)) {
            sum = 0;
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            sum += carry;
            carry = sum / 10;
            newNode.next = new ListNode(sum % 10);
            newNode = newNode.next;
        }

        return head.next;
    }

    public boolean hasCycle2(ListNode head) {
        ListNode slow = head, fast = head;
        if (head == null) {
            return false;
        }

        if (head.next != null) {
            while ((fast != null) && (fast.next != null)) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean hasCycle(ListNode head) {
        Set<ListNode> nodeSet = new HashSet<ListNode>();
        while ((nodeSet.contains(head) == false) && (head != null)) {
            nodeSet.add(head);
            head = head.next;
        }

        if (head == null) {
            return false;
        }
        return true;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> nodeSet = new HashSet<>();
        while (headA != null) {
            nodeSet.add(headA);
            headA = headA.next;
        }

        while ((nodeSet.contains(headB) == false) && (headB != null)) {
            headB = headB.next;
        }
        if (headB == null) {
            return null;
        }
        return headB;
    }

    public ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        ListNode h1 = headA, h2 = headB;

        while ((h1 != null) || (h2 != null)) {
            if ((h1 == h2) && (h1 != null) && (h2 != null)) {
                return h1;
            }

            if (h1 == null) {
                h1 = headB;
                continue;
            }
            if (h2 == null) {
                h2 = headA;
                continue;
            }
            h1 = h1.next;
            h2 = h2.next;
        }

        return null;
    }

    public boolean isPalindrome(ListNode head) {
        ListNode s = head, f = head, d = s, prev = null;
        int count = 1;
        while ((f != null) && (f.next != null)) {
            ++count;
            d = s;
            s = s.next;
            f = f.next.next;
        }

        // for single node
        if (count == 1) {
            return true;
        }

        // Even ke liye
        if (f == null) {
            d.next = null;
        }

        // For odd no of node
        if (f.next == null) {
            d.next = null;
            d = s;
            s = s.next;
        }

        f = s.next;
        while (f != null) {
            s.next = prev;
            prev = s;
            s = f;
            f = f.next;
        }
        s.next = prev;
        prev = head;

        while ((s != null) && (prev != null)) {
            if (s.val != prev.val) {
                return false;
            }
            s = s.next;
            prev = prev.next;
        }

        return true;
    }

    public ListNode detectCycle(ListNode head) {
        Set<ListNode> nodeSet = new HashSet<>();

        while ((nodeSet.contains(head) == false) && (head != null)) {
            nodeSet.add(head);
            head = head.next;
        }

        return head;
    }

    public static void main(String[] args) {
        LinkedList lLink = new LinkedList();

        lLink.append(3);
        lLink.push(2);
        lLink.push(1);
        lLink.printLinkedList();
        lLink.insertBetween(lLink.head.next, 4);
        lLink.printLinkedList();
    }
}
